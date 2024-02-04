// Licensed under the MIT License.

// Prime Summations

#r "nuget: Open.Numeric.Primes, 2.0.1"

using System;
using System.Diagnostics;
using Open.Numeric.Primes;

const int MaxSearch = 100;
int term = -1;
int[] partitions = new int[MaxSearch];

partitions[0] = 1;

Stopwatch start = Stopwatch.StartNew();

foreach (int p in Prime.Numbers.Take(MaxSearch))
{
    for (int j = p; j < MaxSearch; j++)
    {
        partitions[j] += partitions[j - p];
    }
}

for (int n = 0; n < partitions.Length; n++)
{
    if (partitions[n] > 5000)
    {
        term = n;

        break;
    }
}

start.Stop();
Console.WriteLine("0077{0,64}    {1:f6}", term, start.Elapsed.TotalSeconds);
