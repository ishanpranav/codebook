// Licensed under the MIT License.

// Distinct Prime Factors of a Product of Array

#include "../lib/euler.h"
#include "../lib/factor_iterator.h"

bool lazy;
struct Sieve primes;

int distinctPrimeFactors(int values[], int valuesSize)
{
    if (!lazy)
    {
        euler_ok(sieve(&primes, 1000));

        lazy = true;
    }

    int count = 0;
    bool set[1000] = { 0 };

    for (int i = 0; i < valuesSize; i++)
    {   
        struct FactorIterator it;

        for (factor_begin(&it, values[i], &primes);
            !factor_end(&it);
            factor_next(&it))
        {
            if (!set[it.current])
            {
                count++;
                set[it.current] = true;
            }
        }
    }

    return count;
}

void finalizeDistinctPrimeFactors()
{
    finalize_sieve(&primes);
}
