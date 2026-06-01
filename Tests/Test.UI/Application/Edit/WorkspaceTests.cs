using Macad.Test.UI.Framework;
using NUnit.Framework;

namespace Macad.Test.UI.Application.Edit;

public class WorkspaceTests : UITestBase
{        
    [SetUp]
    public void SetUp()
    {
        Reset();
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void GridEnabled()
    {
        MainWindow.Ribbon.SelectTab(RibbonTabs.Edit);
        var enabled = Pipe.GetValue<bool>("$Context.WorkspaceController.Workspace.GridEnabled");
        Assert.AreEqual(enabled, MainWindow.Ribbon.IsChecked("ShowGrid"));

        enabled = !enabled;
        MainWindow.Ribbon.ClickButton("ShowGrid");
        Assert.AreEqual(enabled, Pipe.GetValue<bool>("$Context.WorkspaceController.Workspace.GridEnabled"));
        Assert.AreEqual(enabled, MainWindow.Ribbon.IsChecked("ShowGrid"));

        enabled = !enabled;
        MainWindow.Ribbon.ClickButton("ShowGrid");
        Assert.AreEqual(enabled, Pipe.GetValue<bool>("$Context.WorkspaceController.Workspace.GridEnabled"));
        Assert.AreEqual(enabled, MainWindow.Ribbon.IsChecked("ShowGrid"));
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void GridType()
    {
        MainWindow.Ribbon.SelectTab(RibbonTabs.Edit);
        MainWindow.Ribbon.OpenSplitButtonMenu("ShowGrid");
        var menu = new ContextMenuAdaptor(MainWindow);
        menu.ClickMenuItem("CircGrid");
        Assert.AreEqual("Circular", Pipe.GetValue("$Context.WorkspaceController.Workspace.GridType"));

        MainWindow.Ribbon.OpenSplitButtonMenu("ShowGrid");
        menu = new ContextMenuAdaptor(MainWindow);
        menu.ClickMenuItem("RectGrid");
        Assert.AreEqual("Rectangular", Pipe.GetValue("$Context.WorkspaceController.Workspace.GridType"));
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    public void SnappingEnable()
    {
        MainWindow.Ribbon.SelectTab(RibbonTabs.Edit);
        Assert.That(MainWindow.Ribbon.IsChecked("SnapEnable"), Is.True);
        MainWindow.Ribbon.ClickButton("SnapEnable");
        Assert.That(Pipe.GetValue<bool>("$Context.EditorState.SnappingEnabled"), Is.False);
        MainWindow.Ribbon.ClickButton("SnapEnable");
        Assert.That(Pipe.GetValue<bool>("$Context.EditorState.SnappingEnabled"), Is.True);
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    [TestCase("SnapToGrid", "SnapToGridSelected")]
    [TestCase("SnapToVertex", "SnapToVertexSelected")]
    [TestCase("SnapToEdge", "SnapToEdgeSelected")]
    [TestCase("SnapToAux", "SnapToAuxSelected")]
    public void SnapToEnable(string button, string property)
    {
        MainWindow.Ribbon.SelectTab(RibbonTabs.Edit);
        Assert.That(MainWindow.Ribbon.IsChecked("SnapEnable"), Is.True);
        Assert.That(MainWindow.Ribbon.IsChecked(button), Is.True);
        Assert.That(MainWindow.Ribbon.IsEnabled(button), Is.True);

        MainWindow.Ribbon.ClickButton("SnapEnable");
        Assert.That(MainWindow.Ribbon.IsChecked(button), Is.True);
        Assert.That(MainWindow.Ribbon.IsEnabled(button), Is.False);

        MainWindow.Ribbon.ClickButton("SnapEnable");
        Assert.That(MainWindow.Ribbon.IsEnabled(button), Is.True);

        MainWindow.Ribbon.ClickButton(button);
        Assert.That(Pipe.GetValue<bool>($"$Context.EditorState.{property}"), Is.False);
        MainWindow.Ribbon.ClickButton(button);
        Assert.That(Pipe.GetValue<bool>($"$Context.EditorState.{property}"), Is.True);
    }

    //--------------------------------------------------------------------------------------------------

    [Test]
    [TestCase("Midpoint")]
    [TestCase("TrisectionPoint")]
    [TestCase("CenterPoint")]
    [TestCase("QuadrantPoint")]
    [TestCase("WorkplaneIntersection")]
    [TestCase("Extension")]
    [TestCase("IntersectionPoint")]
    [TestCase("TangentPoint")]
    public void SnapToAuxCategory(string category)
    {
        MainWindow.Ribbon.SelectTab(RibbonTabs.Edit);
        Assert.That(Pipe.GetValue("$Context.EditorState.SnapToAuxCategories"), Does.Contain(category));

        MainWindow.Ribbon.OpenSplitButtonMenu("SnapToAux");
        var menu = MainWindow.FindContextMenu();
        Assert.That(menu, Is.Not.Null);
        menu.ClickMenuItem($"SnapToAux-{category}");
        Assert.That(Pipe.GetValue("$Context.EditorState.SnapToAuxCategories"), Does.Not.Contain(category));

        MainWindow.Ribbon.OpenSplitButtonMenu("SnapToAux");
        menu = MainWindow.FindContextMenu();
        Assert.That(menu, Is.Not.Null);
        menu.ClickMenuItem($"SnapToAux-{category}");
        Assert.That(Pipe.GetValue("$Context.EditorState.SnapToAuxCategories"), Does.Contain(category));
    }

}