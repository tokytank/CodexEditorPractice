# Asset Governance Lab Next Steps

## Active Direction

The next development target is the first real functional layer after the editor entry point:

- build the asset scan service
- define request/result data structures
- connect the editor module to scanning without building the full results UI yet

## Recommended Next Module

### Scan service

Create the first scan pipeline around `AssetRegistry`.

#### Goals

- add a project-facing scan request type
- add a scan result type
- add a minimal asset record type
- add an editor-owned orchestration point for triggering scans
- return enough data to prove the pipeline works for `/Game`

#### Suggested placement

- Runtime:
  - scan request/result structs
  - asset record structs
  - shared enums or lightweight identifiers
- Editor:
  - subsystem or service entry for invoking scans
  - temporary logging or debug output
  - glue from the tab to the scan entry point

## Acceptance Criteria

- The plugin can trigger a scan of `/Game`
- The scan can enumerate assets without loading them directly
- The result can be inspected in logs or temporary debug output
- The editor still builds cleanly after the new scan layer is added

## Design Constraints

- Do not mix real rule evaluation into the first scan pass
- Do not build the full results table yet
- Prefer `AssetRegistry` and `FAssetData`, not eager asset loading
- Keep UI and scan logic separate

## After That

Once scan service is stable, the next likely step is:

- add the first rule engine layer
- start with naming, redirector, and dependency boundary checks
