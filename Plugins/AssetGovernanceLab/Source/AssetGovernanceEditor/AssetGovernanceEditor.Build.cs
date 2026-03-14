using UnrealBuildTool;

public class AssetGovernanceEditor : ModuleRules
{
	public AssetGovernanceEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core"
			});

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"AssetGovernanceRuntime",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Slate",
				"SlateCore",
				"ToolMenus",
				"UnrealEd"
			});
	}
}
