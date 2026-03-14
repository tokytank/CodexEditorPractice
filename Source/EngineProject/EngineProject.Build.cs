// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EngineProject : ModuleRules
{
	public EngineProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ModularGameplay", "GameFeatures" });
	}
}
