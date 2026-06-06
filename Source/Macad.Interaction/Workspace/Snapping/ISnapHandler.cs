using Macad.Core;
using System;
using System.Collections.Generic;

namespace Macad.Interaction;

[Flags]
public enum SnapModes
{
    None      = 0,
    Grid      = 1 << 0,
    Vertex    = 1 << 1,
    Edge      = 1 << 2,
    Face      = 1 << 3,
    Auxiliary = 1 << 7
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------

public class SnapInfo(SnapModes mode)
{
    public SnapModes Mode { get; } = mode;
    public string TargetName { get; set; }

    public static readonly SnapInfo Empty = new(SnapModes.None);
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------

public interface ISnapHandler
{
    SnapModes SupportedModes { get; set; }
    SnapInfo CurrentInfo { get; set; }

    bool NeedActiveSubshapes(SubshapeType subshapeType);

    // Resets any state, including registered auxiliary points
    void Reset();

    //--------------------------------------------------------------------------------------------------

    public delegate void SnapInfoEventHandler(SnapInfo snapInfo);
    static event SnapInfoEventHandler SnapInfoChanged;
    
    protected static void RaiseSnapInfoChanged(ISnapHandler instance)
    {
        SnapInfoChanged?.Invoke(instance.CurrentInfo);
    }

    //--------------------------------------------------------------------------------------------------

    public delegate void SnapAuxiliaryFunction(SnapAuxiliaryContext context);
    protected static readonly Dictionary<SnapAuxiliaryCategories, List<SnapAuxiliaryFunction>> AuxiliaryFunctions = [];

    public static void RegisterSnapAuxiliaryFunction(SnapAuxiliaryCategories category, SnapAuxiliaryFunction function)
    {
        if (!AuxiliaryFunctions.ContainsKey(category))
        {
            AuxiliaryFunctions[category] = new();
        }
        AuxiliaryFunctions[category].Add(function);
    }

    public void AddSnapAuxiliaryFunction(SnapAuxiliaryCategories category, SnapAuxiliaryFunction function)
    {}

    //--------------------------------------------------------------------------------------------------

}

//--------------------------------------------------------------------------------------------------
