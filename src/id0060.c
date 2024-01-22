// Licensed under the MIT License.

// Prime Pair Sets

#include <limits.h>
#include <math.h>
#include "../lib/primality_tests/divisor_primality_test.h"
#include "../lib/euler.h"
#include "../lib/sieve.h"
#define MAX_SEARCH 10000

long math_concat(int a, int b)
{
    return a * pow(10, math_length(b, 1)) + b;
}

bool math_is_prime_pair(Sieve primes, int a, int b)
{
    long concat = math_concat(a, b);

    if (sieve_test(primes, concat, divisor_primality_test) != PRIMALITY_PRIME)
    {
        return false;
    }

    concat = math_concat(b, a);

    if (sieve_test(primes, concat, divisor_primality_test) != PRIMALITY_PRIME)
    {
        return false;
    }

    return true;
}

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, MAX_SEARCH);

    euler_ok();

    struct List candidates;

    ex = list(&candidates, 0);

    euler_ok();

    int min = INT_MAX;

    for (long* a = primes.primes.begin; a < primes.primes.end; a++)
    {
        list_clear(&candidates);

        for (long* b = a; b < primes.primes.end; b++)
        {
            if (math_is_prime_pair(&primes, *a, *b))
            {
                ex = list_add(&candidates, *b);

                euler_ok();
            }
        }

        for (long* b = candidates.begin; b < candidates.end; b++)
        {
            for (long* c = b + 1; c < candidates.end; c++)
            {
                if (!math_is_prime_pair(&primes, *b, *c))
                {
                    continue;
                }

                for (long* d = c + 1; d < candidates.end; d++)
                {
                    if (!math_is_prime_pair(&primes, *b, *d) ||
                        !math_is_prime_pair(&primes, *c, *d))
                    {
                        continue;
                    }

                    for (long* e = d + 1; e < candidates.end; e++)
                    {
                        int sum = *a + *b + *c + *d + *e;

                        if (sum >= min ||
                            !math_is_prime_pair(&primes, *b, *e) ||
                            !math_is_prime_pair(&primes, *c, *e) ||
                            !math_is_prime_pair(&primes, *d, *e))
                        {
                            continue;
                        }

                        min = sum;
                    }
                }
            }
        }
    }

    finalize_sieve(&primes);
    finalize_list(&candidates);

    return euler_submit(60, min, start);
}
