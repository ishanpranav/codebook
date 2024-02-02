// Licensed under the MIT License.

// Singular Integer Right Triangles

using System;
using System.Numerics;

int[] PythagoreanTripletCounts(int max)
{
    int[] result = new int[max];
    int end = (int)Math.Sqrt(max);

    for (int m = 1; m < end; m += 2)
    {
        for (int n = 2; n < end; n += 2)
        {
            if (BigInteger.GreatestCommonDivisor(m, n) != 1)
            {
                continue;
            }

            int sum = Math.Abs(m * m - n * n) + m * m + n * n + 2 * m * n;

            for (int kSum = sum; kSum < max; kSum += sum)
            {
                result[kSum]++;
            }
        }
    }

    return result;
}

Stopwatch start = Stopwatch.StartNew();

int count = 0;

foreach (int tripletCount in PythagoreanTripletCounts(1500001))
{
    if (tripletCount == 1)
    {
        count++;
    }
}

start.Stop();
Console.WriteLine("0075{0,64}    {1:f6}", count, start.Elapsed.TotalSeconds);
