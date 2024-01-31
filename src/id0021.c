// Licensed under the MIT License.

// Amicable Numbers

#include "../lib/euler.h"
#include "../lib/exception.h"
#include "../lib/factor_iterator.h"

int main(void)
{
    int sum = 0;
    struct Sieve primes;
    clock_t start = clock();
    int* d = malloc(sizeof * d * 9998);

    euler_assert(d);
    euler_ok(sieve(&primes, 0));

    for (int a = 2; a < 10000; a++)
    {
        d[a - 2] = factor_divisor_sum(a, &primes) - a;
    }

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
