// Licensed under the MIT License.

// Count Primes

#include "../lib/binary_search.h"
#include "../lib/euler.h"
#include "../lib/sieve.h"

bool lazy;
struct Sieve primes;

int countPrimes(int n) 
{
    if (n <= 2)
    {
        return 0;
    }

    if (!lazy)
    {
        euler_ok(sieve(&primes, 5000000l));

        lazy = true;
    }
    
    long long m = n;

    return binary_search_rank(
        &m, 
        primes.primes.items, 
        primes.primes.count, 
        sizeof(long long),
        long_long_comparer);
}

void finalizeCountPrimes()
{
    finalize_sieve(&primes);
}
