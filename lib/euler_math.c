// Licensed under the MIT License.

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "euler_math.h"

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
