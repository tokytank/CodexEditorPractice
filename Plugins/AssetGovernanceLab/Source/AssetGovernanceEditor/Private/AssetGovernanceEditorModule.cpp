#include "AssetGovernanceEditorModule.h"

#include "AssetGovernanceEditorCommands.h"
#include "SAssetGovernancePlaceholderPanel.h"

#include "Framework/Commands/UICommandList.h"
#include "Modules/ModuleManager.h"
#include "ToolMenus.h"
#include "Widgets/Docking/SDockTab.h"
#include "Framework/Docking/TabManager.h"

#define LOCTEXT_NAMESPACE "FAssetGovernanceEditorModule"

namespace AssetGovernanceEditor
{
	static const FName AppIdentifier(TEXT("AssetGovernanceLab"));
}

void FAssetGovernanceEditorModule::StartupModule()
{
	FAssetGovernanceEditorCommands::Register();

	PluginCommands = MakeShared<FUICommandList>();
	PluginCommands->MapAction(
		FAssetGovernanceEditorCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FAssetGovernanceEditorModule::PluginButtonClicked));

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		AssetGovernanceEditor::AppIdentifier,
		FOnSpawnTab::CreateRaw(this, &FAssetGovernanceEditorModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("AssetGovernanceTabTitle", "Asset Governance Lab"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	UToolMenus::RegisterStartupCallback(
		FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FAssetGovernanceEditorModule::RegisterMenus));
}

void FAssetGovernanceEditorModule::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(AssetGovernanceEditor::AppIdentifier);
	FAssetGovernanceEditorCommands::Unregister();
	PluginCommands.Reset();
}

void FAssetGovernanceEditorModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);

	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools");
	FToolMenuSection& Section = Menu->FindOrAddSection("AssetGovernance");
	Section.AddMenuEntryWithCommandList(FAssetGovernanceEditorCommands::Get().OpenPluginWindow, PluginCommands);
}

void FAssetGovernanceEditorModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(AssetGovernanceEditor::AppIdentifier);
}

TSharedRef<SDockTab> FAssetGovernanceEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SAssetGovernancePlaceholderPanel)
		];
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAssetGovernanceEditorModule, AssetGovernanceEditor)

