using Macad.Common;
using Macad.Core;
using Macad.Occt;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using static Macad.Interaction.ISnapHandler;
using Point = System.Windows.Point;

namespace Macad.Interaction;

public abstract class SnapBase : BaseObject, ISnapHandler, IDisposable
{
    #region Properties

    public SnapModes SupportedModes
    {
        get;
        set
        {
            field = value; 
            RaisePropertyChanged();
            WorkspaceController?.Selection?.Invalidate();
        }
    }

    //--------------------------------------------------------------------------------------------------

    public SnapInfo CurrentInfo
    {
        get;
        set
        {
            if (Equals(value, field)) return;
            field = value;
            RaisePropertyChanged();
            ISnapHandler.RaiseSnapInfoChanged(this);
        }
    }

    //--------------------------------------------------------------------------------------------------

    public WorkspaceController WorkspaceController
    {
        get;
        set
        {
            Debug.Assert(field == null || field == value, "WorkspaceController cannot be changed");
            field = value;
        }
    }

    //--------------------------------------------------------------------------------------------------

    internal SnapAuxiliaryContext AuxiliaryContext { get; private set; }

    //--------------------------------------------------------------------------------------------------

    protected bool ShowVisualsTopmost { get; set; }

    //--------------------------------------------------------------------------------------------------

    #endregion

    #region Member / n'tor

    protected SnapBase()
    {
        InteractiveContext.Current.EditorState.PropertyChanged += _EditorState_PropertyChanged;
    }

    //--------------------------------------------------------------------------------------------------

    protected virtual void Dispose(bool disposing)
    {
        if (disposing)
        {
            CleanupAux();
            _InstanceAuxiliaryFunctions?.Clear();
            InteractiveContext.Current.EditorState.PropertyChanged -= _EditorState_PropertyChanged;
        }
    }

    public void Dispose()
    {
        Dispose(true);
        GC.SuppressFinalize(this);
    }

    //--------------------------------------------------------------------------------------------------

    #endregion

    #region Callbacks

    void _EditorState_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
    {
        if (e.PropertyName is nameof(InteractiveContext.EditorState.SnappingEnabled)
                           or nameof(InteractiveContext.EditorState.SnapToEdgeSelected)
                           or nameof(InteractiveContext.EditorState.SnapToAuxSelected)
                           or nameof(InteractiveContext.EditorState.SnapToVertexSelected)
                           or nameof(InteractiveContext.EditorState.SnapToAuxCategories))
        {
            CleanupAux();
        }
    }

    //--------------------------------------------------------------------------------------------------

    #endregion

    #region Common Snap Functions

    protected (SnapModes Mode, Pnt Point, Geom_Curve Curve) Snap(ViewportController viewportController, Point screenPoint, TopoDS_Shape shapeToSnap)
    {
        if (shapeToSnap == null)
        {
            CleanupAux();
            return (SnapModes.None, Pnt.Origin, null);
        }

        if (SupportedModes.HasFlag(SnapModes.Vertex)
            && InteractiveContext.Current.EditorState.SnapToVertexSelected
            && shapeToSnap.ShapeType() == TopAbs_ShapeEnum.VERTEX)
        {
            // On Vertex
            var point = BRep_Tool.Pnt(shapeToSnap.ToVertex());
            _AddAuxElements(point);
            return (SnapModes.Vertex, point, null);
        }

        if (SupportedModes.HasFlag(SnapModes.Edge)
            && InteractiveContext.Current.EditorState.SnapToEdgeSelected
            && shapeToSnap.ShapeType() == TopAbs_ShapeEnum.EDGE)
        {
            // On Edge
            var edge = shapeToSnap.ToEdge();
            double umin = 0, umax = 0;
            var curve = BRep_Tool.Curve(edge, ref umin, ref umax);
            if (curve == null && BRepLib.BuildCurve3d(edge))
            {
                curve = BRep_Tool.Curve(edge, ref umin, ref umax);
            }

            if (curve != null)
            {
                _AddAuxElements(edge, curve, umin, umax);
                if(viewportController.ScreenToPointOnCurve(Convert.ToInt32(screenPoint.X), Convert.ToInt32(screenPoint.Y), curve, out Pnt edgePnt))
                {
                    return (SnapModes.Edge, edgePnt, curve);
                }
            }
        }

        CleanupAux();

        return (SnapModes.None, Pnt.Origin, null);
    }

    //--------------------------------------------------------------------------------------------------

    protected (SnapModes Mode, Pnt Point) Snap(ViewportController viewportController, Point screenPoint, AIS_InteractiveObject aisObjectToSnap)
    {
        if (aisObjectToSnap == null)
        {
            CleanupAux();
            return (SnapModes.None, Pnt.Origin);
        }

        if (SupportedModes.HasFlag(SnapModes.Auxiliary)
            && InteractiveContext.Current.EditorState.SnapToAuxSelected
            && (AuxiliaryContext?.TryGetSnapPoint(viewportController, screenPoint, aisObjectToSnap, out Pnt auxPnt) ?? false))
        {
            // On Auxiliary Element
            return (SnapModes.Auxiliary, auxPnt);
        }

        if (SupportedModes.HasFlag(SnapModes.Vertex) 
            && InteractiveContext.Current.EditorState.SnapToVertexSelected 
            && aisObjectToSnap is AIS_Point aisPoint)
        {
            // On Vertex
            CleanupAux();
            return (SnapModes.Vertex, aisPoint.Component().Pnt());
        }

        CleanupAux();
        return (SnapModes.None, Pnt.Origin);
    }

    //--------------------------------------------------------------------------------------------------
    
    protected (SnapModes Mode, Pnt Point, Geom_Curve Curve) Snap(ViewportController viewportController, Point screenPoint, TopoDS_Shape shapeToSnap, AIS_InteractiveObject aisObjectToSnap)
    {
        SnapModes mode = SnapModes.None;
        Pnt point = Pnt.Origin;
        Geom_Curve curve = null;

        // Try BRepShape first
        if (shapeToSnap != null)
        {
            (mode, point, curve) = Snap(viewportController, screenPoint, shapeToSnap);
        }

        // If none found, try AIS object next
        if (mode == SnapModes.None && aisObjectToSnap != null)
        {
            (mode, point) = Snap(viewportController,screenPoint, aisObjectToSnap);
        }

        return (mode, point, curve);
    }

    //--------------------------------------------------------------------------------------------------

    #endregion

    #region Support Functions

    public double GetSnapOnPlaneDistanceThreshold(ViewportController viewportController)
    {
        var parameterSet = InteractiveContext.Current.Parameters.Get<ViewportParameterSet>();
        return parameterSet.SelectionPixelTolerance * viewportController.PixelSize * viewportController.DpiScale * 1.5;
    }

    //--------------------------------------------------------------------------------------------------

    public virtual bool NeedActiveSubshapes(SubshapeType subshapeType)
    {
        return subshapeType switch
        {
            SubshapeType.Vertex => InteractiveContext.Current.EditorState.SnappingEnabled 
                                   && InteractiveContext.Current.EditorState.SnapToVertexSelected 
                                   && SupportedModes.HasFlag(SnapModes.Vertex),

            SubshapeType.Edge => InteractiveContext.Current.EditorState.SnappingEnabled 
                                 && InteractiveContext.Current.EditorState.SnapToEdgeSelected 
                                 && SupportedModes.HasFlag(SnapModes.Edge),

            _ => false
        };
    }

    //--------------------------------------------------------------------------------------------------
    
    public void Reset()
    {
        CurrentInfo = SnapInfo.Empty;
    }

    //--------------------------------------------------------------------------------------------------

    protected bool ProjectToGrid(ViewportController viewportController, int screenX, int screenY, out Pnt pnt)
    {
        Pln plane = WorkspaceController.Workspace.WorkingPlane;
        if (!viewportController.ScreenToPoint(plane, screenX, screenY, out pnt))
            return false;

        Pnt2d uv = plane.Parameters(pnt);
        Pnt2d gridUv = WorkspaceController.ComputeGridPoint(uv);
        pnt = plane.Value(gridUv);
        return true;
    }

    //--------------------------------------------------------------------------------------------------

    #endregion

    #region Auxiliary Snap

    Dictionary<SnapAuxiliaryCategories, List<SnapAuxiliaryFunction>> _InstanceAuxiliaryFunctions;

    public void AddSnapAuxiliaryFunction(SnapAuxiliaryCategories category, SnapAuxiliaryFunction function)
    {
        _InstanceAuxiliaryFunctions ??= new();
        if (!_InstanceAuxiliaryFunctions.ContainsKey(category))
        {
            _InstanceAuxiliaryFunctions[category] = new();
        }
        _InstanceAuxiliaryFunctions[category].Add(function);
    }

    //--------------------------------------------------------------------------------------------------

    bool _IsAuxEnabled()
    {
        if (!SupportedModes.HasFlag(SnapModes.Auxiliary)
            || !InteractiveContext.Current.EditorState.SnapToAuxSelected)
        {
            CleanupAux();
            return false;
        }
        return true;
    }

    //--------------------------------------------------------------------------------------------------

    void _AddAuxElements(Pnt point)
    {
        if (!_IsAuxEnabled())
            return;

        // No auxiliary points for vertices available
        return;
    }

    //--------------------------------------------------------------------------------------------------

    void _AddAuxElements(TopoDS_Edge edge, Geom_Curve curve, double umin, double umax)
    {
        if (!_IsAuxEnabled())
            return;

        if (AuxiliaryContext?.Edge.Equals(edge) == true)
            return;

        var prevContext = AuxiliaryContext;
        AuxiliaryContext?.Dispose();
        AuxiliaryContext = new(this, edge, curve, umin, umax)
        {
            PreviousCurve = prevContext?.Curve,
            PreviousUMin = prevContext?.UMin ?? 0,
            PreviousUMax = prevContext?.UMax ?? umax,
            ShowVisualsTopmost = ShowVisualsTopmost
        };

        foreach (var (category, funcs) in AuxiliaryFunctions)
        {
            if (category != SnapAuxiliaryCategories.None
                && !InteractiveContext.Current.EditorState.SnapToAuxCategories.HasFlag(category))
                continue;

            funcs.ForEach(func => func(AuxiliaryContext));
        }

        if (_InstanceAuxiliaryFunctions != null)
        {
            foreach (var (category, funcs) in _InstanceAuxiliaryFunctions)
            {
                if (category != SnapAuxiliaryCategories.None
                    && !InteractiveContext.Current.EditorState.SnapToAuxCategories.HasFlag(category))
                    continue;

                funcs.ForEach(func => func(AuxiliaryContext));
            }
        }
    }
    
    //--------------------------------------------------------------------------------------------------

    protected void CleanupAux()
    {
        AuxiliaryContext?.Dispose();
        AuxiliaryContext = null;
    }

    //--------------------------------------------------------------------------------------------------

    #endregion

}

//--------------------------------------------------------------------------------------------------
