// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EnTTue_Project : ModuleRules
{
	public EnTTue_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UnrealEd", "InputCore", "UMG", "Slate", "SlateCore", "Json", "JsonUtilities" });
		PublicDependencyModuleNames.AddRange(new string[] { "EnTT", "EnTTue", "EnTTinspector" });

		PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UnrealEd", "InputCore", "UMG", "Slate", "SlateCore", "Json", "JsonUtilities" });
		PrivateDependencyModuleNames.AddRange(new string[] { "EnTT", "EnTTue", "EnTTinspector" });
	}
}
