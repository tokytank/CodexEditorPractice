# Asset Governance Lab Handoff

## Current State

- Repository branch in active use: `master`
- Remote branch: `origin/master`
- Unreal Engine version: `5.5`
- Current workflow: direct development in the main project workspace
- Historical worktree notes remain in `WORKTREE_PLAYBOOK.md`, but worktrees are no longer the active workflow

## What Is Already Done

### Repository and project state

- The project baseline has been committed and pushed
- `AssetGovernanceLab` is enabled in `EngineProject.uproject`
- Rider project files have been regenerated and now include the plugin modules

### Plugin scaffold

- Plugin descriptor exists at `Plugins/AssetGovernanceLab/AssetGovernanceLab.uplugin`
- Runtime module exists:
  - `AssetGovernanceRuntime.Build.cs`
  - `AssetGovernanceRuntimeModule.h/.cpp`
- Editor module exists:
  - `AssetGovernanceEditor.Build.cs`
  - `AssetGovernanceEditorModule.h/.cpp`

### Editor entry point

- A command class exists for opening the tool window
- A `Nomad Tab` is registered by the editor module
- A `Tools` menu entry is registered
- A placeholder Slate panel is shown when the tab opens

## Why The Modules Are Split

- `AssetGovernanceRuntime` is the low-level layer for reusable data and logic that should not depend on editor-only modules
- `AssetGovernanceEditor` is the editor-only layer for menus, tabs, Slate UI, and other editor integrations
- This keeps runtime logic free of `UnrealEd` and keeps future scan/rule code easier to test and reuse

## Files To Read First Next Time

- `Plugins/AssetGovernanceLab/AssetGovernanceLab.uplugin`
- `Plugins/AssetGovernanceLab/Source/AssetGovernanceEditor/Private/AssetGovernanceEditorModule.cpp`
- `Plugins/AssetGovernanceLab/Source/AssetGovernanceEditor/Private/SAssetGovernancePlaceholderPanel.cpp`
- `Docs/AssetGovernanceLab/NEXT_STEPS.md`

## Current Known Notes

- Generating Rider files requires the Rider generator path, not just Visual Studio project generation
- Full editor target builds are succeeding
- The project still emits a pre-existing warning that `EngineProject` depends on `ModularGameplay` while the `.uproject` does not list that plugin explicitly

## Last Meaningful Commit

- `d7720cb feat: add asset governance editor plugin scaffold`
