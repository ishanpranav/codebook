// Licensed under the MIT License.

// 10001st Prime

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "euler.h"

long math_max_prime(int k)
{
    double logK = log(k);
    
    return ceil(k * logK + k * log(logK));
}

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

long math_prime(int k, long max, bool composites[])
{
    int n = 0;

    for (long i = 2; i < max; i++)
    {
        if (!composites[i - 2])
        {
            n++;
        }

        if (n == k)
        {
            return i;
        }
    }

    return 0;
}

int main(void)
{
    clock_t start = clock();
    long max = math_max_prime(10001);
    bool* composites = calloc(max - 2, sizeof(bool));

    if (!composites)
    {
        euler_throw("Out of memory");
    }

    math_composites(max, composites);

    long p = math_prime(10001, max, composites);

    euler_submit(7, p, start);
    free(composites);

    return 0;
}
