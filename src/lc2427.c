// Licensed under the MIT License.

// Number of Common Factors

#include "../lib/euclidean.h"

int commonFactors(int a, int b)
{
    int result = 0;

    for (int d = gcd(a, b); d; d--)
    {
        if (a % d == 0 && b % d == 0)
        {
            result++;
        }
    }

    return result;
}
