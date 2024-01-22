// Licensed under the MIT License.

// Quadratic Primes

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/sieve.h"

int math_quadratic_prime(Sieve primes, int a, int b)
{
    int n = 0;

    while (sieve_test(primes, labs(n * (n + a) + b), NULL) == PRIMALITY_PRIME)
    {
        n++;
    }

    return n;
}

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 1001);

    euler_ok();

    int maxA = 0;
    int maxB = 0;
    int maxN = 0;

    for (int a = -999; a < 1000; a += 2)
    {
        for (long* b = primes.primes.begin; b < primes.primes.end; b++)
        {
            int n = math_quadratic_prime(&primes, a, *b);

            if (n > maxN)
            {
                maxA = a;
                maxB = *b;
                maxN = n;
            }
        }
    }

    finalize_sieve(&primes);

    long product = maxA * maxB;

    return euler_submit(27, product, start);
}
