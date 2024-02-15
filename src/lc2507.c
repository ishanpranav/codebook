// Licensed under the MIT License.

// Smallest Value After Replacing With Sum of Prime Factors

#include "../lib/euler.h"
#include "../lib/factor_iterator.h"

bool lazy;
struct Sieve primes;

int smallestValue(int n)
{
    if (!lazy)
    {
        euler_ok(sieve(&primes, 10000));

        lazy = true;
    }

    for (;;)
    {    
        int sum = factor_sum(n, &primes);

        if (n == sum)
        {
            break;
        }
        
        n = sum;
    }

    return n;
}

void finalizeSmallestValue()
{
    finalize_sieve(&primes);
}
