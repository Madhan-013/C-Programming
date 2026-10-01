# Build all handbook demos on Windows (PowerShell)
# Usage:  .\build.ps1
# Requires: gcc on PATH (MinGW / MSYS2 / TDM-GCC)

$ErrorActionPreference = "Stop"
New-Item -ItemType Directory -Force -Path bin | Out-Null

$flags = @("-std=c11", "-Wall", "-Wextra", "-O2")
$sources = Get-ChildItem -Path src -Filter "*.c" | Sort-Object Name

foreach ($src in $sources) {
    $out = Join-Path "bin" ($src.BaseName + ".exe")
    Write-Host "Compiling $($src.Name) -> $out"
    & gcc @flags -o $out $src.FullName
    if ($LASTEXITCODE -ne 0) {
        Write-Error "Build failed: $($src.Name)"
        exit 1
    }
}

Write-Host ""
Write-Host "Built $($sources.Count) programs into bin\"
Write-Host "Example: .\bin\01_introduction.exe"
