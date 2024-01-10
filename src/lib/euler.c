// Licensed under the MIT License.

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "euler.h"

void euler_submit(int id, long long result, clock_t start)
{
    printf(
        "%04d%64lld    %lf\n", 
        id, 
        result,
        (double)(clock() - start) / CLOCKS_PER_SEC);
}

long math_natural_sum(long n)
{
    return n * (n + 1) / 2;
}

long math_get_primes(long max, long result[])
{
    bool* composites = calloc(max - 2, sizeof * composites);

    if (!composites)
    {
        return -1;
    }

    double sqrtMax = sqrt(max);

    for (long m = 2; m <= sqrtMax; m++)
    {
        if (composites[m - 2])
        {
            continue;
        }

        for (long n = m * m; n < max; n += m)
        {
            composites[n - 2] = true;
        }
    }

    long count = 0;

    for (long i = 0; i < max - 2; i++)
    {
        if (!composites[i])
        {
            result[count] = i + 2;
            count++;
        }
    }

    free(composites);

    return count;
}
