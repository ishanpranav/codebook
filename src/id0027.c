// Licensed under the MIT License.

// Quadratic Primes

#include "../lib/euler.h"
#include "../lib/sieve.h"

static int math_quadratic_prime(Sieve primes, int a, int b)
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
    int maxA = 0;
    int maxB = 0;
    int maxN = 0;
    struct Sieve primes;
    clock_t start = clock();
    
    euler_ok(sieve(&primes, 1001));

    for (int a = -999; a < 1000; a += 2)
    {
        long long* begin = primes.primes.items;
        long long* end = begin + primes.primes.count;
        
        for (long long* b = begin; b < end; b++)
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

    long product = maxA * maxB;

    finalize_sieve(&primes);

    return euler_submit(27, product, start);
}
