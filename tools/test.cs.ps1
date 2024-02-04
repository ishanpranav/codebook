# Licensed under the MIT License.

Get-ChildItem -Path ../src -Filter *.csx | ForEach-Object {
    Dotnet-Script $_.FullName
}
