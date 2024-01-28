// Licensed under the MIT License.

// Totient Maximum

#include "../lib/euler.h"
#include "../lib/sieve_iterator.h"

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 0);

    euler_ok();

    long primorial = 1;
    struct SieveIterator it;

    for (sieve_begin(&it, &primes); ; sieve_next(&it))
    {
        long product = primorial * *it.current;

        if (product > 1000000l)
        {
            break;
        }

        primorial = product;
    }

    return euler_submit(69, primorial, start);
}
