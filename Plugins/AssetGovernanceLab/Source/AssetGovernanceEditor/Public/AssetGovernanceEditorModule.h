#pragma once

#include "Templates/SharedPointer.h"
#include "Modules/ModuleManager.h"

class FSpawnTabArgs;
class FUICommandList;
class SDockTab;

class FAssetGovernanceEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void RegisterMenus();
	void PluginButtonClicked();
	TSharedRef<SDockTab> OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs);

private:
	TSharedPtr<FUICommandList> PluginCommands;
};
