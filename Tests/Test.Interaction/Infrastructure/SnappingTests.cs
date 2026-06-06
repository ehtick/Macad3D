using System.IO;
using Macad.Test.Utils;
using Macad.Core;
using Macad.Core.Shapes;
using Macad.Interaction.Editors.Shapes;
using NUnit.Framework;
using Macad.Interaction;
using Macad.Occt;

namespace Macad.Test.Interaction.Infrastructure;

[TestFixture]
public class SnappingTests
{
    const string _BasePath = @"Interaction\Infrastructure\Snapping";

    //--------------------------------------------------------------------------------------------------

    [SetUp]
    public void SetUp()
    {
        Context.InitWithView(500);
        var ctx = Context.Current;
        ctx.Workspace.GridEnabled = true;
        ctx.Workspace.GridStep = 2.0;
    }

    [TearDown]
    public void TearDown()
    {
        Context.Current.Deinit();
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToRectGrid()
    {
        var ctx = Context.Current;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToGridSelected = true;

        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(102, 245);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToRectGrid01"));
            ctx.MoveTo(147, 272);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToRectGrid02"));
            ctx.MoveTo(175, 213);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToRectGrid03"));

            ctx.EditorState.SnapToGridSelected = false;
            ctx.MoveTo(175, 213);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToRectGrid90"));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToScaledRectGrid()
    {
        var ctx = Context.Current;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToGridSelected = true;
        ctx.Workspace.GridStep = 1.0;
        var viewportParameterSet = InteractiveContext.Current.Parameters.Get<ViewportParameterSet>();
        viewportParameterSet.VisualGridStepMinPixel = 10;
        viewportParameterSet.VisualGridMinStepsOnScreen = 10;

        ctx.ViewportController.Zoom(-20.0);
        Assume.That(ctx.WorkspaceController.VisualGridMultiplier, Is.GreaterThan(1.0));

        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(102, 245);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToScaledRectGrid"));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToCircGrid()
    {
        var ctx = Context.Current;
        ctx.Workspace.GridType = Workspace.GridTypes.Circular;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToGridSelected = true;

        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(102, 245);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToCircGrid01"));
            ctx.MoveTo(147, 272);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToCircGrid02"));
            ctx.MoveTo(175, 213);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToCircGrid03"));

            ctx.EditorState.SnapToGridSelected = false;
            ctx.MoveTo(175, 213);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToCircGrid90"));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToScaledCircGrid()
    {
        var ctx = Context.Current;
        ctx.Workspace.GridType = Workspace.GridTypes.Circular;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToGridSelected = true; 
        ctx.Workspace.GridStep = 1.0;
        var viewportParameterSet = InteractiveContext.Current.Parameters.Get<ViewportParameterSet>();
        viewportParameterSet.VisualGridStepMinPixel = 10;
        viewportParameterSet.VisualGridMinStepsOnScreen = 10;

        ctx.ViewportController.Zoom(-20.0);
        Assume.That(ctx.WorkspaceController.VisualGridMultiplier, Is.GreaterThan(1.0));
        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(102, 245);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToScaledCircGrid"));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToVertex()
    {
        var refBody = TestGeomGenerator.CreateBox().Body;

        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToGridSelected = false;
        ctx.EditorState.SnapToVertexSelected = true;

        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(54, 357);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToVertex01"));
            ctx.MoveTo(255, 254);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToVertex02"));
            ctx.MoveTo(252, 482);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToVertex03"));

            ctx.EditorState.SnapToVertexSelected = false;
            ctx.MoveTo(252, 482);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToVertex90"));
        });
    }

    //--------------------------------------------------------------------------------------------------
        
    [Test]
    public void SnapToEdge()
    {
        var refBody = TestGeomGenerator.CreateBox().Body;

        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToGridSelected = false;
        ctx.EditorState.SnapToEdgeSelected = true;

        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(54, 357);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToEdge01"));
            ctx.MoveTo(168, 200);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToEdge02"));
            ctx.MoveTo(251, 462);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToEdge03"));

            ctx.EditorState.SnapToEdgeSelected = false;
            ctx.MoveTo(251, 462);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToEdge90"));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void FindSelectedSnapshape()
    {
        var refBody = TestGeomGenerator.CreateBox().Body;

        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToGridSelected = false;
        ctx.EditorState.SnapToVertexSelected = true;

        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(252, 482);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "FindSelectedSnapshape01"));
            ctx.ClickAt(252, 482);
            ctx.ClickAt(249, 495);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "FindSelectedSnapshape02"));
            ctx.MoveTo(445, 139);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "FindSelectedSnapshape03"));
            ctx.ClickAt(445, 139);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "FindSelectedSnapshape04"));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToAuxCleanup()
    {
        var refBody = TestGeomGenerator.CreateBox().Body;
        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.Workspace.GridEnabled = false;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToAuxSelected = true;
        ctx.EditorState.SnapToEdgeSelected = true;
        ctx.EditorState.SnapToAuxCategories = SnapAuxiliaryCategories.TrisectionPoint | SnapAuxiliaryCategories.Extension;
        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            // Select edge, all points visible
            ctx.MoveTo(251, 462);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext?.Edge, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(4));
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxCleanup01"));
            
            // Aux points invisible when aux snapping is turned off
            ctx.EditorState.SnapToAuxSelected = false;
            ctx.MoveTo(251, 462);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Null);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxCleanup02"));
            ctx.EditorState.SnapToAuxSelected = true;
            ctx.MoveTo(251, 462);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext?.Edge, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(4));

            // Aux points still there if edge is no longer hilighted
            ctx.MoveTo(240, 462);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext?.Edge, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(4));
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxCleanup06"));

            // Aux points change when another edge is hilighted
            ctx.MoveTo(190, 214);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext?.Edge, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(4));
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxCleanup05"));

            // Are points active?
            ctx.MoveTo(188, 214);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxCleanup07"));

            // Are axes active?
            ctx.MoveTo(21, 119);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxCleanup08"));

            // Aux points (and edge hilight) invisible when edge snapping is turned off
            ctx.EditorState.SnapToEdgeSelected = false;
            ctx.MoveTo(251, 462);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.Edge, Is.Null);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxCleanup03"));
            ctx.EditorState.SnapToEdgeSelected = true;
            ctx.MoveTo(251, 462);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext?.Edge, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(4));

            // Aux points invisible when aux categories are turned off
            var savedCats = ctx.EditorState.SnapToAuxCategories;
            ctx.EditorState.SnapToAuxCategories = SnapAuxiliaryCategories.None;
            ctx.MoveTo(251, 462);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext?.Edge, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));
            ctx.EditorState.SnapToAuxCategories = savedCats;
            ctx.MoveTo(251, 462);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext?.Edge, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(4));

            // All aux points should be cleared when tool is stopped
            ctx.WorkspaceController.CurrentTool.Stop();
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxCleanup04"));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToAuxMidpoint()
    {
        var box = TestGeomGenerator.CreateBox();
        var cyl = TestGeomGenerator.CreateCylinder();
        cyl.Body.Position = new(-10, -10, 0);
        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.Workspace.GridEnabled = false;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToAuxSelected = true;
        ctx.EditorState.SnapToEdgeSelected = true;
        ctx.EditorState.SnapToAuxCategories = SnapAuxiliaryCategories.Midpoint;
        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(251, 400);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(1));
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxMidpoint01"));

            // Not on closed curves
            ctx.MoveTo(251, 223);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToAuxTrisection()
    {
        var box = TestGeomGenerator.CreateBox();
        var cyl = TestGeomGenerator.CreateCylinder();
        cyl.Body.Position = new(-10, -10, 0);
        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.Workspace.GridEnabled = false;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToAuxSelected = true;
        ctx.EditorState.SnapToEdgeSelected = true;
        ctx.EditorState.SnapToAuxCategories = SnapAuxiliaryCategories.TrisectionPoint;
        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(251, 400);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxTrisection01"));
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(2));

            // Not on closed curves
            ctx.MoveTo(251, 223);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToAuxCenter()
    {
        var box = TestGeomGenerator.CreateBox();
        var cyl = TestGeomGenerator.CreateCylinder();
        cyl.Body.Position = new(-10, -10, 0);
        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.Workspace.GridEnabled = false;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToAuxSelected = true;
        ctx.EditorState.SnapToEdgeSelected = true;
        ctx.EditorState.SnapToAuxCategories = SnapAuxiliaryCategories.CenterPoint;
        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(251, 223);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(1));
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxCenter01"));

            // Not on linear edges
            ctx.MoveTo(251, 400);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToAuxQuadrants()
    {
        var box = TestGeomGenerator.CreateBox();
        var cyl = TestGeomGenerator.CreateCylinder();
        cyl.Body.Position = new(-10, -10, 0);
        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.Workspace.GridEnabled = false;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToAuxSelected = true;
        ctx.EditorState.SnapToEdgeSelected = true;
        ctx.EditorState.SnapToAuxCategories = SnapAuxiliaryCategories.QuadrantPoint;
        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(251, 223);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(4));
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxQuadrants01"));

            // Not on linear edges
            ctx.MoveTo(251, 400);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToWorkingPlaneIntersection()
    {
        var box = TestGeomGenerator.CreateBox();
        var cyl = TestGeomGenerator.CreateCylinder();
        cyl.Body.Position = new(-10, -10, 0);
        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.Workspace.GridEnabled = false;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToAuxSelected = true;
        ctx.EditorState.SnapToEdgeSelected = true;
        ctx.EditorState.SnapToAuxCategories = SnapAuxiliaryCategories.WorkplaneIntersection;
        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.Workspace.WorkingPlane = new(new(0, 0, 0), Dir.DZ.Rotated(Ax1.OY, 0.5));
            ctx.MoveTo(251, 400);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(1));
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxWPIntersection01"));
            
            ctx.MoveTo(181, 210);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(2));
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxWPIntersection02"));

            ctx.Workspace.WorkingPlane = new(new(0, 0, 0), Dir.DZ);
            ctx.MoveTo(283, 318);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToAuxExtension()
    {
        var box = TestGeomGenerator.CreateBox();
        var cyl = TestGeomGenerator.CreateCylinder();
        cyl.Body.Position = new(-10, -10, 0);
        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.Workspace.GridEnabled = false;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToAuxSelected = true;
        ctx.EditorState.SnapToEdgeSelected = true;
        ctx.EditorState.SnapToAuxCategories = SnapAuxiliaryCategories.Extension;
        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(223, 322);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxExtension01"));
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(2));

            // Not on closed curves
            ctx.MoveTo(251, 223);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));
        });
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnapToAuxIntersectionPoint()
    {
        var box = TestGeomGenerator.CreateBox();
        var fillet =Fillet.Create(box.Body);
        fillet.Radius = 3;
        fillet.AddAllEdges();
        var cyl = TestGeomGenerator.CreateCylinder();
        cyl.Body.Position = new(-10, -10, 0);
        var ctx = Context.Current;
        ctx.ViewportController.ZoomFitAll();
        ctx.Workspace.GridEnabled = false;
        ctx.EditorState.SnappingEnabled = true;
        ctx.EditorState.SnapToAuxSelected = true;
        ctx.EditorState.SnapToEdgeSelected = true;
        ctx.EditorState.SnapToAuxCategories = SnapAuxiliaryCategories.IntersectionPoint;
        ctx.WorkspaceController.StartTool(new CreateBoxTool());

        Assert.Multiple(() =>
        {
            ctx.MoveTo(271, 299);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));

            ctx.MoveTo(212, 342);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));

            // Move twice to ensure that the previous curve is not overwritten
            ctx.MoveTo(285, 341);
            ctx.MoveTo(285, 341);
            AssertHelper.IsSameViewport(Path.Combine(_BasePath, "SnapToAuxIntersectionPoint01"));
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(3));

            // Not on closed curves
            ctx.MoveTo(251, 223);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext, Is.Not.Null);
            Assert.That(((SnapBase)ctx.WorkspaceController.CurrentTool.GetSnapHandler()).AuxiliaryContext.AuxVisuals.Count, Is.EqualTo(0));
        });
    }
}