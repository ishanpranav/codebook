// Licensed under the MIT License.

// Diophantine Equation

#r "System.Numerics"

using System;
using System.Diagnostics;
using System.Numerics;

int maxD = -1;
BigInteger maxX = 0;
Stopwatch start = Stopwatch.StartNew();

for (int d = 2; d <= 1000; d++)
{
    double sqrt = Math.Sqrt(d);

    if (sqrt % 1 == 0)
    {
        continue;
    }

    BigInteger isqrt = (BigInteger)sqrt;
    BigInteger a = isqrt;
    BigInteger h = 0;
    BigInteger k = 1;
    BigInteger x0 = 0, x1 = 1, x2 = isqrt;
    BigInteger y0 = 0, y1 = 0, y2 = 1;

    do
    {
        h = a * k - h;
        k = (d - h * h) / k;
        a = (isqrt + h) / k;
        x0 = x1;
        x1 = x2;
        x2 = a * x1 + x0;
        y0 = y1;
        y1 = y2;
        y2 = a * y1 + y0;
    }
    while (x2 * x2 - d * y2 * y2 != 1);

    if (x2 > maxX)
    {
        maxD = d;
        maxX = x2;
    }
}

start.Stop();
Console.WriteLine("0066{0,64}    {1:f6}", maxD, start.Elapsed.TotalSeconds);
