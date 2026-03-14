# Asset Governance Lab Worktree Playbook

This repository uses the main workspace only for roadmap control and cross-cutting architecture decisions.
All Asset Governance Lab implementation work happens in dedicated git worktrees.

## Current Baseline

- Base snapshot branch: `master`
- Mainline branch: `codex/agl-mainline`
- Naming rule: `codex/agl-XX-topic`
- Worktree path rule: `E:\Learning\EngineProject_wt_XX_topic`

## Sequence

| Step | Branch | Purpose | Base |
| --- | --- | --- | --- |
| WT00 | `codex/agl-00-bootstrap` | Repo bootstrap and worktree workflow | `master` |
| WT01 | `codex/agl-01-plugin-skeleton` | Plugin skeleton and module split | `codex/agl-mainline` |
| WT02 | `codex/agl-02-editor-entry` | Menu, commands, empty tab | previous completed branch |
| WT03 | `codex/agl-03-scan-service` | Asset scan subsystem and models | previous completed branch |
| WT04 | `codex/agl-04-rule-engine` | Rule execution and first violations | previous completed branch |
| WT05 | `codex/agl-05-settings` | Developer settings and config wiring | previous completed branch |
| WT06 | `codex/agl-06-results-ui` | Slate results UI | previous completed branch |
| WT07 | `codex/agl-07-content-browser-hooks` | Content Browser integration | previous completed branch |
| WT08 | `codex/agl-08-safe-actions` | Redirector fix, rename preview, export | previous completed branch |
| WT09 | `codex/agl-09-test-assets-and-automation` | Test fixtures and automation | previous completed branch |

## Rules

- The main workspace does not implement feature code.
- Each worktree handles one topic only.
- A new worktree is created only after the previous topic is accepted.
- Child sessions should explain architecture, design rationale, tradeoffs, and rejected alternatives.

## Notes

- `Plugins/UE5NiagaraComputeExample` originally contained nested git metadata. To make the outer repository snapshot usable in worktrees, that nested `.git` directory is backed up as `.git.nested-backup` and ignored by the outer repo.
- Generated Unreal folders are ignored at the repository root and inside plugins.

## Helper

Use `Tools/AssetGovernance/New-AGLWorktree.ps1` to create the next worktree from the agreed base branch.
