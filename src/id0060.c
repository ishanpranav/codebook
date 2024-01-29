// Licensed under the MIT License.

// Prime Pair Sets

#include <limits.h>
#include <math.h>
#include "../lib/primality_tests/miller_rabin_primality_test.h"
#include "../lib/euler.h"
#include "../lib/sieve.h"
#define MAX_SEARCH 10000

static bool math_is_prime_pair(Sieve primes, int a, int b)
{
    long concat = math_concat(a, b);
    PrimalityTest primalityTest = miller_rabin_primality_test;

    if (sieve_test(primes, concat, primalityTest) != PRIMALITY_PRIME)
    {
        return false;
    }

    concat = math_concat(b, a);

    if (sieve_test(primes, concat, primalityTest) != PRIMALITY_PRIME)
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

    ex = list(&candidates, sizeof(long long), 0);

    euler_ok();

    int min = INT_MAX;
    long long* primesBegin = primes.primes.items;
    long long* primesEnd = primesBegin + primes.primes.count;

    for (long long* a = primesBegin; a < primesEnd; a++)
    {
        list_clear(&candidates);

        for (long long* b = a; b < primesEnd; b++)
        {
            if (math_is_prime_pair(&primes, *a, *b))
            {
                ex = list_add(&candidates, b);

                euler_ok();
            }
        }

        long long* candidatesBegin = candidates.items;
        long long* candidatesEnd = candidatesBegin + candidates.count;

        for (long long* b = candidatesBegin; b < candidatesEnd; b++)
        {
            for (long long* c = b + 1; c < candidatesEnd; c++)
            {
                if (!math_is_prime_pair(&primes, *b, *c))
                {
                    continue;
                }

                for (long long* d = c + 1; d < candidatesEnd; d++)
                {
                    if (!math_is_prime_pair(&primes, *b, *d) ||
                        !math_is_prime_pair(&primes, *c, *d))
                    {
                        continue;
                    }

                    for (long long* e = d + 1; e < candidatesEnd; e++)
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
