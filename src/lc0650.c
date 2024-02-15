// Licensed under the MIT License.

// 2 Keys Keyboard

#include "../lib/euler.h"
#include "../lib/factor_iterator.h"

bool lazy;
struct Sieve primes;

int minSteps(int n) 
{
    if (!lazy)
    {
        euler_ok(sieve(&primes, 10000));

        lazy = true;
    }

    return factor_sum(n, &primes);
}

void finalizeMinSteps()
{
    finalize_sieve(&primes);
}
