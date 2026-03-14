#pragma once

#include "Modules/ModuleManager.h"

class FAssetGovernanceRuntimeModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
