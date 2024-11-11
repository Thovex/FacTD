using UnrealBuildTool;

public class EnTTinspector : ModuleRules
{
    public EnTTinspector(ReadOnlyTargetRules Target) : base(Target)
    {
        CppStandard = CppStandardVersion.Cpp20;

        PrivatePCHHeaderFile = "EnTTinspector.h";
        
        PublicDependencyModuleNames.AddRange(new [] { "Core", "Slate", "SlateCore", "CoreUObject", "Engine", "InputCore", "UnrealEd", "EnTT", "PropertyEditor", "EditorWidgets", "Json", "JsonUtilities"});
        PrivateDependencyModuleNames.AddRange(new [] { "EditorStyle" });
    }
}