# Licensed under the MIT License.

Get-ChildItem -Path ../src -Filter *.py | ForEach-Object {
    Python3 $_.FullName
}
