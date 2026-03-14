#include "AssetGovernanceEditorCommands.h"

#include "Framework/Commands/UICommandInfo.h"
#include "Styling/AppStyle.h"

#define LOCTEXT_NAMESPACE "FAssetGovernanceEditorCommands"

FAssetGovernanceEditorCommands::FAssetGovernanceEditorCommands()
	: TCommands<FAssetGovernanceEditorCommands>(
		TEXT("AssetGovernanceEditor"),
		LOCTEXT("AssetGovernanceEditorContext", "Asset Governance Lab"),
		NAME_None,
		FAppStyle::GetAppStyleSetName())
{
}

void FAssetGovernanceEditorCommands::RegisterCommands()
{
	UI_COMMAND(
		OpenPluginWindow,
		"Asset Governance Lab",
		"Open the Asset Governance Lab tool window.",
		EUserInterfaceActionType::Button,
		FInputChord());
}

#undef LOCTEXT_NAMESPACE
