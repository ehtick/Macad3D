using Macad.Common;
using Macad.Interaction.Visual;
using Macad.Occt;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Windows;
using Macad.Core;

namespace Macad.Interaction;

[Flags]
public enum SnapAuxiliaryCategories
{
    None                  = 0,
    Midpoint              = 1 << 0,
    TrisectionPoint       = 1 << 1,
    CenterPoint           = 1 << 2,
    QuadrantPoint         = 1 << 3,
    WorkplaneIntersection = 1 << 4,
    Extension             = 1 << 5,
    IntersectionPoint     = 1 << 6,
    TangentPoint          = 1 << 7,
    All                   = 0xff
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------

public sealed class SnapAuxiliaryContext(SnapBase snapHandler, TopoDS_Edge edge, Geom_Curve curve, double uMin, double uMax) : IDisposable
{
    internal record AuxElement(string Name, Ax1 Position);

    public SnapBase SnapHandler { get; } = snapHandler;
    public TopoDS_Edge Edge { get; } = edge;
    public Geom_Curve Curve { get; } = curve;
    public double UMin { get; } = uMin;
    public double UMax { get; } = uMax;
    public Geom_Curve PreviousCurve { get; init; }
    public double PreviousUMin { get; init; }
    public double PreviousUMax { get; init; }
    internal Dictionary<VisualObject, AuxElement> AuxVisuals { get; } = [];
    internal bool ShowVisualsTopmost { get; init; }

    ~SnapAuxiliaryContext()
    {
        Dispose();
    }

    public void Dispose()
    {
        AuxVisuals.Keys.ForEach(obj => obj.Remove());
        AuxVisuals.Clear();
        GC.SuppressFinalize(this);
    }

    //--------------------------------------------------------------------------------------------------

    public bool TryGetSnapPoint(ViewportController viewportController, Point screenPoint, AIS_InteractiveObject aisObject, out Pnt pnt)
    {
        pnt = Pnt.Origin;

        var auxObject = AuxVisuals.Keys.FirstOrDefault(obj => obj.AisObject?.Equals(aisObject) ?? false);
        if (auxObject == null)
            return false;

        if (auxObject is Axis)
        {
            return viewportController.ScreenToPointOnCurve(Convert.ToInt32(screenPoint.X), Convert.ToInt32(screenPoint.Y), 
                                                           new Geom_Line(AuxVisuals[auxObject].Position), 
                                                           out pnt);
        }
        else
        {
            pnt = AuxVisuals[auxObject].Position.Location;
            return true;
        }
    }

    //--------------------------------------------------------------------------------------------------

    public string TryGetAuxTargetName(AIS_InteractiveObject aisObject)
    {
        var key = AuxVisuals.Keys.FirstOrDefault(obj => obj.AisObject?.Equals(aisObject) ?? false);
        return key == null ? null : AuxVisuals[key].Name;
    }
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------

public static class SnapAuxiliaryFunctions
{
    #region Registration

    class SnapAuxiliaryFunctionAttribute(SnapAuxiliaryCategories category) : Attribute
    {
        public SnapAuxiliaryCategories Category { get; } = category;
    }

    //--------------------------------------------------------------------------------------------------

    [AutoRegister]
    internal static void RegisterMethods()
    {
        var methods = typeof(SnapAuxiliaryFunctions).GetMethods(BindingFlags.NonPublic | BindingFlags.Static)
            .Where(mi => mi.GetCustomAttribute<SnapAuxiliaryFunctionAttribute>() != null);
        foreach (var method in methods)
        {
            var attr = method.GetCustomAttribute<SnapAuxiliaryFunctionAttribute>();
            ISnapHandler.RegisterSnapAuxiliaryFunction(attr.Category, method.CreateDelegate<ISnapHandler.SnapAuxiliaryFunction>());
        }
    }

    //--------------------------------------------------------------------------------------------------

    #endregion

    #region Support Functions

    public static void AddAuxMarker(SnapAuxiliaryContext context, string name, Pnt location)
    {
        if (!context.SnapHandler.SupportedModes.HasFlag(SnapModes.Vertex))
            return;

        Marker.Styles style = Marker.Styles.Bitmap;
        if(context.ShowVisualsTopmost)
            style |= Marker.Styles.Topmost;
        Marker marker = new Marker(context.SnapHandler.WorkspaceController, style, Marker.BallImage);
        marker.Set(location);
        marker.IsSelectable = true;
        context.AuxVisuals.Add(marker, new(name, new(location, Dir.DX)));
    }

    //--------------------------------------------------------------------------------------------------

    public static void AddAuxAxis(SnapAuxiliaryContext context, string name, Ax1 axis, double length)
    {
        if (!context.SnapHandler.SupportedModes.HasFlag(SnapModes.Edge))
            return;

        Axis.Style style = Axis.Style.NoResize;
        if (context.ShowVisualsTopmost)
            style |= Axis.Style.Topmost;
        Axis visual = new Axis(context.SnapHandler.WorkspaceController, style);
        visual.Set(axis);
        visual.IsSelectable = true;
        visual.Color = Colors.Default;
        visual.Length = length;
        context.AuxVisuals.Add(visual, new(name, new(axis.Location, axis.Direction)));
    }

    //--------------------------------------------------------------------------------------------------

    public static void AddHintLine(SnapAuxiliaryContext context, Pnt start, Pnt end)
    {
        HintStyle style = HintStyle.Dashed;
        if (context.ShowVisualsTopmost)
            style |= HintStyle.Topmost;
        HintLine visual = new HintLine(context.SnapHandler.WorkspaceController, style);
        visual.Set(start, end);
        context.AuxVisuals.Add(visual, new("Hint", Ax1.OX));
    }

    //--------------------------------------------------------------------------------------------------

    #endregion

    #region Auxiliary Element Implementations

    [SnapAuxiliaryFunction(SnapAuxiliaryCategories.Midpoint)]
    static void _Aux_Midpoint(SnapAuxiliaryContext context)
    {
        Geom_Curve curve = context.Curve;
        double umin = context.UMin;
        double umax = context.UMax;

        if(curve == null)
            return;
        if (umin.Equals(umax))
            return;
        if (curve.IsPeriodic() && umin.Distance(umax).Equals(curve.Period()))
            return;

        Pnt midPnt = new Pnt();
        curve.D0(umin.Lerp(umax, 0.5), ref midPnt);
        AddAuxMarker(context, "Midpoint", midPnt);
    }

    //--------------------------------------------------------------------------------------------------

    [SnapAuxiliaryFunction(SnapAuxiliaryCategories.TrisectionPoint)]
    static void _Aux_Trisections(SnapAuxiliaryContext context)
    {
        Geom_Curve curve = context.Curve;
        double umin = context.UMin;
        double umax = context.UMax;

        if (curve == null)
            return;
        if (umin.Equals(umax))
            return;
        if (curve.IsClosed() && umin.Distance(umax).Equals(curve.Period()))
            return;

        Pnt pnt = new Pnt();
        curve.D0(umin.Lerp(umax, 1.0 / 3.0), ref pnt);
        AddAuxMarker(context, "Trisection", pnt);
        curve.D0(umin.Lerp(umax, 2.0 / 3.0), ref pnt);
        AddAuxMarker(context, "Trisection", pnt);
    }

    //--------------------------------------------------------------------------------------------------

    [SnapAuxiliaryFunction(SnapAuxiliaryCategories.CenterPoint)]
    static void _Aux_Center(SnapAuxiliaryContext context)
    {
        if (context.Curve is not Geom_Conic conic)
            return;

        AddAuxMarker(context, "Center", conic.Location());
    }

    //--------------------------------------------------------------------------------------------------

    [SnapAuxiliaryFunction(SnapAuxiliaryCategories.QuadrantPoint)]
    static void _Aux_QuadrantPoint(SnapAuxiliaryContext context)
    {
        if (context.Curve is not Geom_Conic conic)
            return;

        double u = context.UMin;
        double step = conic.Period() / 4.0;
        for (int i = 0; i < 4; i++, u += step)
        {
            Pnt pnt = new Pnt();
            context.Curve.D0(u, ref pnt);
            AddAuxMarker(context, "Quadrant", pnt);
        }
    }

    //--------------------------------------------------------------------------------------------------

    [SnapAuxiliaryFunction(SnapAuxiliaryCategories.WorkplaneIntersection)]
    static void _Aux_WorkplaneIntersection(SnapAuxiliaryContext context)
    {
        if (context.Curve == null)
            return;

        GeomAPI_IntCS intCS = new(context.Curve, new Geom_Plane(InteractiveContext.Current.Workspace.WorkingPlane));
        if (!intCS.IsDone() || intCS.NbPoints() <= 0)
            return;

        for (int i = 1; i <= intCS.NbPoints(); i++)
        {
            AddAuxMarker(context, "Intersection", intCS.Point(i));
        }
    }

    //--------------------------------------------------------------------------------------------------

    [SnapAuxiliaryFunction(SnapAuxiliaryCategories.Extension)]
    static void _Aux_Extension(SnapAuxiliaryContext context)
    {
        Geom_Curve curve = context.Curve;
        double umin = context.UMin;
        double umax = context.UMax;

        if (curve == null)
            return;
        if (umin.Equals(umax))
            return;
        if (curve.IsClosed() && umin.Distance(umax).Equals(curve.Period()))
            return;

        Pnt p1 = new Pnt();
        Vec v1 = new Vec();
        curve.D1(umin, ref p1, ref v1);
        Pnt p2 = new Pnt();
        Vec v2 = new Vec();
        curve.D1(umax, ref p2, ref v2);

        double length = 50.0;

        AddAuxAxis(context, "Tangent Extent", new(p1, v1.ToDir().Reversed()), length);
        AddAuxAxis(context, "Tangent Extent", new(p2, v2.ToDir()), length);
    }

    //--------------------------------------------------------------------------------------------------

    [SnapAuxiliaryFunction(SnapAuxiliaryCategories.IntersectionPoint)]
    static void _Aux_IntersectionPoint(SnapAuxiliaryContext context)
    {
        if (context.Curve == null || context.PreviousCurve == null)
            return;

        Geom_Curve curve = context.Curve;
        Geom_Curve otherCurve = context.PreviousCurve;

        GeomAPI_ExtremaCurveCurve extrema = new(curve, otherCurve);
        if(extrema.IsParallel() || extrema.NbExtrema() == 0)
            return;

        Pnt p1 = new Pnt();
        Pnt p2 = new Pnt();
        extrema.NearestPoints(ref p1, ref p2);
        if (p1.SquareDistance(p2) > 1e-6)
            return;

        if (extrema.NbExtrema() == 1)
        {
            Pnt s1 = curve.Value(context.UMin);
            Pnt s2 = curve.Value(context.UMax);
            AddHintLine(context, s1.SquareDistance(p1) < s2.SquareDistance(p1) ? s1 : s2, p1);

            s1 = otherCurve.Value(context.UMin);
            s2 = otherCurve.Value(context.UMax);
            AddHintLine(context, s1.SquareDistance(p1) < s2.SquareDistance(p1) ? s1 : s2, p1);
        }

        for (int i = 1; i <= extrema.NbExtrema(); i++)
        {
            extrema.Points(i, ref p1, ref p2);
            if (p1.SquareDistance(p2) > 1e-6)
                continue;

            AddAuxMarker(context, "Intersection", p1);
        }
    }

    //--------------------------------------------------------------------------------------------------

    #endregion
}