// Licensed under the MIT License.

// Amicable Numbers

#include "../lib/euler.h"
#include "../lib/factor_iterator.h"

int main(void)
{
    int sum = 0;
    struct Sieve primes;
    clock_t start = clock();
    int* d = malloc(10000 * sizeof * d);

    d[0] = 0;
    d[1] = 1;

    euler_assert(d);
    euler_ok(sieve(&primes, 0));

    for (int a = 2; a < 10000; a++)
    {
        d[a] = factor_divisor_sum(a, &primes) - a;
    }

    for (int a = 2; a < 10000; a++)
    {
        int b = d[a];

        if (a != b && b < 10000 && a == d[b])
        {
            sum += a;
        }
    }

    free(d);
    finalize_sieve(&primes);

    return euler_submit(21, sum, start);
}
