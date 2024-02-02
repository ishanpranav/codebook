// Licensed under the MIT License.

#include <math.h>
#include <stdlib.h>
#include "euclidean.h"

long gcd(long a, long b)
{
    while (b > 0)
    {
        long r = a % b;

        a = b;
        b = r;
    }

    return a;
}

long lcm(long a, long b)
{
    return (a / gcd(a, b)) * b;
}

int* pythagorean_triplet_counts(long max)
{    
    int* result = calloc(max, sizeof * result);

    if (!result)
    {
        return NULL;
    }

    long end = (long)sqrt(max);

    for (long m = 1; m < end; m += 2)
    {
        for (long n = 2; n < end; n += 2)
        {
            if (gcd(m, n) != 1)
            {
                continue;
            }

            long sum = labs(m * m - n * n) + m * m + n * n + 2 * m * n;

            for (long kSum = sum; kSum < max; kSum += sum)
            {
                result[kSum]++;
            }
        }
    }

    return result;
}
