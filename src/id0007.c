// Licensed under the MIT License.

// 10001st Prime

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "euler.h"

void math_composites(long max, bool result[])
{
    double sqrtMax = sqrt(max);

    for (long m = 2; m < sqrtMax; m++)
    {
        if (result[m - 2])
        {
            continue;
        }

        for (long n = m * m; n < max; n += m)
        {
            result[n - 2] = true;
        }
    }
}

long math_prime(int k)
{
    double logK = log(k);
    long max = ceil(k * logK + k * log(logK));
    bool* composites = calloc(max - 2, sizeof(bool));

    if (!composites)
    {
        return -1;
    }

    math_composites(max, composites);

    int n = 0;

    for (long i = 2; i < max; i++)
    {
        if (!composites[i - 2])
        {
            n++;
        }

        if (n == k)
        {
            free(composites);

            return i;
        }
    }

    free(composites);

    return 0;
}

int main(void)
{
    clock_t start = clock();
    long term = math_prime(10001);

    if (term < 0)
    {
        euler_throw("Out of memory");

        return 1;
    }

    euler_submit(7, term, start);

    return 0;
}
