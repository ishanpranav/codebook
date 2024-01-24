// Licensed under the MIT License.

// Cyclic Figurate Numbers

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

bool IsCyclic(int a, int b)
{
    return a / 100 == b % 100;
}

bool IsPolygonal(int s, int x)
{
    double sM2 = s - 2;
    double sM4 = sM2 - 2;
    double term = (Math.Sqrt(8 * sM2 * x + sM4 * sM4) + sM4) / (2 * sM2);

    return term == (int)term;
}

bool IsOctagonalOrSmallerPolygonal(int x)
{
    for (int s = 3; s < 6; s++)
    {
        if (IsPolygonal(s, x))
        {
            return true;
        }
    }

    return IsPolygonal(7, x) || IsPolygonal(8, x);
}

bool IsPermutedPolygonal(IReadOnlyCollection<int> values)
{
    if (values.Count != 6)
    {
        return false;
    }

    int flags = 0;

    foreach (int x in values)
    {
        for (int s = 8; s >= 3; s--)
        {
            if (IsPolygonal(s, x))
            {
                flags |= (1 << s);

                break;
            }
        }
    }

    return flags == 0b111111000;
}

int CyclicPolygonalSum()
{
    HashSet<int> polygonals = new HashSet<int>();

    for (int x = 1000; x < 10000; x++)
    {
        if (IsOctagonalOrSmallerPolygonal(x))
        {
            polygonals.Add(x);
        }
    }

    foreach (int a in polygonals)
    {
        foreach (int b in polygonals)
        {
            if (!IsCyclic(a, b))
            {
                continue;
            }

            foreach (int c in polygonals)
            {
                if (!IsCyclic(b, c))
                {
                    continue;
                }

                foreach (int d in polygonals)
                {
                    if (!IsCyclic(c, d))
                    {
                        continue;
                    }

                    foreach (int e in polygonals)
                    {
                        if (!IsCyclic(d, e))
                        {
                            continue;
                        }

                        foreach (int f in polygonals)
                        {
                            if (!IsCyclic(e, f) || !IsCyclic(f, a))
                            {
                                continue;
                            }

                            HashSet<int> values = new HashSet<int>()
                            {
                                a, b, c, d, e, f
                            };

                            if (!IsPermutedPolygonal(values))
                            {
                                continue;
                            }

                            return values.Sum();
                        }
                    }
                }
            }
        }
    }

    return -1;
}

Stopwatch start = Stopwatch.StartNew();

int result = CyclicPolygonalSum();

start.Stop();

Console.WriteLine("0061{0,64}    {1:f6}", result, start.Elapsed.TotalSeconds);
