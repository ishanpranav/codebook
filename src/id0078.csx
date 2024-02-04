// Licensed under the MIT License.

// Coin Partitions

using System;
using System.Diagnostics;

const int MaxSearch = 100000;
long[] partitions = new long[MaxSearch];

partitions[0] = 1;

Stopwatch start = Stopwatch.StartNew();

for (int i = 1; i < MaxSearch; i++)
{
    long current = 0;

    for (int j = 0; ; j++)
    {
        int k = j / 2 + 1;

        if (j % 2 == 1)
        {
            k = -k;
        }

        int pentagonal = k * (3 * k - 1) / 2;

        if (i < pentagonal)
        {
            break;
        }

        if (j % 4 < 2)
        {
            current += partitions[i - pentagonal];
        }
        else
        {
            current -= partitions[i - pentagonal];
        }

        current %= 1000000;
    }

    if (current < 0)
    {
        current = (current + 1000000) % 1000000;
    }

    partitions[i] = current;
}

int term = -1;

for (int n = 0; n < MaxSearch; n++)
{
    if (partitions[n] == 0)
    {
        term = n;

        break;
    }
}

start.Stop();
Console.WriteLine("0078{0,64}    {1:f6}", term, start.Elapsed.TotalSeconds);
