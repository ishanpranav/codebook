// Licensed under the MIT License.

// Totient Maximum

#include "../lib/euler.h"
#include "../lib/sieve_iterator.h"

int main(void)
{
    long primorial = 1;
    struct Sieve primes;
    struct SieveIterator it;
    clock_t start = clock();

    euler_ok(sieve(&primes, 0));

    for (sieve_begin(&it, &primes); ; sieve_next(&it))
    {
        long product = primorial * *it.current;

        if (product > 1000000l)
        {
            break;
        }

        primorial = product;
    }

    finalize_sieve(&primes);
    
    return euler_submit(69, primorial, start);
}
