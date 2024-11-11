using UnrealBuildTool;

public class EnTTue : ModuleRules
{
	public EnTTue(ReadOnlyTargetRules Target) : base(Target)
	{
		CppStandard = CppStandardVersion.Default;
		
		bLegacyPublicIncludePaths = false;
		bLegacyParentIncludePaths = false;

		ShadowVariableWarningLevel = WarningLevel.Error;
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PrivatePCHHeaderFile = "EnTTue.h";
		PublicDependencyModuleNames.AddRange(new string[] { "Niagara", "Core", "CoreUObject", "Engine", "InputCore", "EnTT", "EnTTinspector", "Slate", "SlateCore", "Json", "JsonUtilities"});
		PrivateDependencyModuleNames.AddRange(new string[] { "EnTTinspector" });

	}
}