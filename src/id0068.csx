#r "nuget: Combinatorics, 2.0.0"

using System;
using System.Collections.Generic;
using System.Diagnostics;
using Combinatorics.Collections;

string max = "";
Stopwatch start = Stopwatch.StartNew();

List<int> ring = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

foreach (var l in new Permutations<int>(ring))
{
    if (l[0] > l[3] || l[0] > l[5] || l[0] > l[7] || l[0] > l[9] ||
        (l[3] != 10 && l[5] != 10 && l[7] != 10 && l[9] != 10))
    {
        continue;
    }

    int sum = l[0] + l[1] + l[2];

    if (l[2] + l[3] + l[4] != sum || l[4] + l[5] + l[6] != sum ||
        l[6] + l[7] + l[8] != sum || l[8] + l[9] + l[1] != sum)
    {
        continue;
    }

    string value = string.Concat(
        l[0], l[1], l[2],
        l[3], l[2], l[4],
        l[5], l[5], l[6],
        l[7], l[6], l[8],
        l[9], l[8], l[1]);

    if (value.CompareTo(max) > 0)
    {
        max = value;
    }
}

start.Stop();
Console.WriteLine("0068{0,64}    {1:f6}", max, start.Elapsed.TotalSeconds);
