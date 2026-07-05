using Macad.Occt;
using System;
using System.Linq;

namespace Macad.Core.Shapes;

public static class SubshapeReferenceUtils
{
    public delegate void SubshapeNameCallback(string name, TopoDS_Shape shape, int index);

    //--------------------------------------------------------------------------------------------------

    public static void CreateSubshapeNames<T>(T algo, SubshapeNameCallback addSubshapeName) where T : class
    {
        switch (algo)
        {
            case BRepPrim_Wedge wedge:
                _CreateSubshapeNames(wedge, addSubshapeName);
                return;

            case BRepPrim_OneAxis oneAxis:
                _CreateSubshapeNames(oneAxis, addSubshapeName);
                return;
        }
    }

    //--------------------------------------------------------------------------------------------------

    static void _CreateSubshapeNames(BRepPrim_Wedge wedge, SubshapeNameCallback addSubshapeName)
    {
        foreach (var d1 in Enum.GetValues<BRepPrim_Direction>())
        {
            if (wedge.HasFace(d1))
            {
                addSubshapeName($"{d1}", wedge.Face(d1), 0);
            }

            foreach (var d2 in Enum.GetValues<BRepPrim_Direction>())
            {
                // Skip impossible values (e.g. XMin and XMax)
                // Check here to avoid throwing a Standard_DomainError exception in HasEdge()
                if ((int)d1 / 2 == (int)d2 / 2)
                    continue;

                if (wedge.HasEdge(d1, d2))
                {
                    addSubshapeName($"{d1}{d2}", wedge.Edge(d1, d2), 0);
                }
            }
        }
    }

    //--------------------------------------------------------------------------------------------------

    static void _CreateSubshapeNames(BRepPrim_OneAxis oneAxis, SubshapeNameCallback addSubshapeName)
    {
        addSubshapeName("Lateral", oneAxis.LateralFace(), 0);
        if (oneAxis.HasBottom())
        {
            addSubshapeName("Bottom", oneAxis.BottomFace(), 0);
            if (oneAxis.HasSides())
            {
                addSubshapeName("SideBottom", oneAxis.StartBottomEdge(), 0);
                addSubshapeName("SideBottom", oneAxis.EndBottomEdge(), 1);
            }
        }
        var edge = oneAxis.BottomEdge();
        if (edge != null)
        {
            addSubshapeName("Bottom", edge, 0);
        }

        if (oneAxis.HasTop())
        {
            addSubshapeName("Top", oneAxis.TopFace(), 0);
            if (oneAxis.HasSides())
            {
                addSubshapeName("SideTop", oneAxis.StartTopEdge(), 0);
                addSubshapeName("SideTop", oneAxis.EndTopEdge(), 1);
            }
        }
        edge = oneAxis.TopEdge();
        if (edge != null)
        {
            addSubshapeName("Top", edge, 0);
        }

        if (oneAxis.HasSides())
        {
            addSubshapeName("Axis", oneAxis.AxisEdge(), 0);
            addSubshapeName("Side", oneAxis.StartFace(), 0);
            addSubshapeName("Side", oneAxis.StartEdge(), 0);
            addSubshapeName("Side", oneAxis.EndFace(), 1);
            addSubshapeName("Side", oneAxis.EndEdge(), 1);
        }
        else
        {
            var seamEdge = oneAxis.LateralWire().Edges().FirstOrDefault(edge => !BRep_Tool.IsClosed(edge));
            if (seamEdge != null)
            {
                addSubshapeName("Seam", seamEdge, 0);
            }
        }
    }

    //--------------------------------------------------------------------------------------------------

}