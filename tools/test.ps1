# Licensed under the MIT License.

for ($i = 1; $i -le 7; $i++)
{
    Invoke-Expression "./../id000${i}.exe"
}

Get-Content './../data/id0008.txt' | ./../id0008.exe
./../id0009.exe
./../id0010.exe
Get-Content './../data/id0011.txt' | ./../id0011.exe
./../id0012.exe
Get-Content './../data/id0013.txt' | ./../id0013.exe

for ($i = 14; $i -le 17; $i++)
{
    Invoke-Expression "./../id00${i}.exe"
}

Get-Content './../data/id0018.txt' | ./../id0018.exe

for ($i = 19; $i -le 21; $i++)
{
    Invoke-Expression "./../id00${i}.exe"
}

Get-Content './../data/id0022.txt' | ./../id0022.exe

for ($i = 23; $i -le 41; $i++)
{
    Invoke-Expression "./../id00${i}.exe"
}

Get-Content './../data/id0042.txt' | ./../id0042.exe

for ($i = 43; $i -le 53; $i++)
{
    Invoke-Expression "./../id00${i}.exe"
}

Get-Content './../data/id0054.txt' | ./../id0054.exe

for ($i = 55; $i -le 58; $i++)
{
    Invoke-Expression "./../id00${i}.exe"
}

Get-Content './../data/id0059.txt' | ./../id0059.exe

for ($i = 60; $i -le 64; $i++)
{
    Invoke-Expression "./../id00${i}.exe"
}

Python3 ../src/id0065.py
./../id0066.exe
Get-Content './../data/id0067.txt' | ./../id0018.exe 67

for ($i = 68; $i -le 80; $i++)
{
    Invoke-Expression "./../id00${i}.exe"
}
