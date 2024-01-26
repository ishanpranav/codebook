// Licensed under the MIT License.

// Amicable Numbers

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/exception.h"
#include "../lib/factor_iterator.h"

int main(void)
{
    clock_t start = clock();
    int* d = malloc(sizeof * d * 9998);
    Exception ex;

    if (!d)
    {
        ex = EXCEPTION_OUT_OF_MEMORY;

        euler_ok();
    }

    struct Sieve primes;

    ex = sieve(&primes, 0);

    euler_ok();

    for (int a = 2; a < 10000; a++)
    {
        d[a - 2] = factor_divisor_sum(a, &primes) - a;
    }

    int sum = 0;

    for (int a = 2; a < 10000; a++)
    {
        int b = d[a - 2];

        if (a != b && a == d[b - 2])
        {
            sum += a;
        }
    }

    free(d);
    finalize_sieve(&primes);

    return euler_submit(21, sum, start);
}
