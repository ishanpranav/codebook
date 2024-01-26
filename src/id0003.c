// Licensed under the MIT License.

// Largest Prime Factor

#include <math.h>
#include "../lib/euler.h"
#include "../lib/factor_iterator.h"

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 30);

    euler_ok();

    struct FactorIterator it;

    factor_begin(&it, 600851475143ll, &primes);

    while (!factor_end(&it))
    {
        factor_next(&it);
    }

    finalize_sieve(&primes);
    
    return euler_submit(3, it.current, start);
}
