// Licensed under the MIT License.

// Truncatable Primes

#include <math.h>
#include "../lib/euler.h"
#include "../lib/sieve.h"

int main(void)
{
    long sum = 0;
    int count = 0;
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 0);

    euler_ok();

    struct SieveIterator it;
    
    sieve_begin(&it, &primes);

    for (sieve_skip(&it, 4); count < 11; sieve_next(&it))
    {
        long right = *it.current;

        while (right && sieve_test(&primes, right, NULL) == PRIMALITY_PRIME)
        {
            right /= 10;
        }

        if (right)
        {
            continue;
        }

        long left = *it.current;
        long orderOfMagnitude = pow(10, (int)log10(left));

        while (left && sieve_test(&primes, left, NULL) == PRIMALITY_PRIME)
        {
            left %= orderOfMagnitude;
            orderOfMagnitude /= 10;
        }

        if (left)
        {
            continue;
        }

        sum += *it.current;
        count++;
    }

    finalize_sieve(&primes);
    
    return euler_submit(37, sum, start);
}
