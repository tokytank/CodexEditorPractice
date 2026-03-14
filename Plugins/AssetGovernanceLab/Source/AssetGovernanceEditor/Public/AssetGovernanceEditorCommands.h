#pragma once

#include "Framework/Commands/Commands.h"

class FUICommandInfo;

class FAssetGovernanceEditorCommands : public TCommands<FAssetGovernanceEditorCommands>
{
public:
	FAssetGovernanceEditorCommands();

	virtual void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> OpenPluginWindow;
};
