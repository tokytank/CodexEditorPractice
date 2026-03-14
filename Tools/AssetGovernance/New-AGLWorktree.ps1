param(
    [Parameter(Mandatory = $true)]
    [string]$Index,

    [Parameter(Mandatory = $true)]
    [string]$Topic,

    [Parameter(Mandatory = $true)]
    [string]$BaseBranch,

    [string]$WorkspaceRoot = "E:\Learning"
)

$repoRoot = "E:/Learning/EngineProject"
$normalizedIndex = $Index.PadLeft(2, '0')
$branchName = "codex/agl-$normalizedIndex-$Topic"
$safeTopic = $Topic.Replace('-', '_')
$worktreePath = Join-Path $WorkspaceRoot ("EngineProject_wt_{0}_{1}" -f $normalizedIndex, $safeTopic)

Write-Host "Creating branch $branchName from $BaseBranch"
Write-Host "Worktree path: $worktreePath"

git -c safe.directory=$repoRoot worktree add $worktreePath -b $branchName $BaseBranch
