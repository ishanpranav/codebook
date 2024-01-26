// Licensed under the MIT License.

// Largest Prime Factor

#include <math.h>
#include "../lib/euler.h"
#include "../lib/sieve_iterator.h"

static long long math_max_prime_factor(Sieve primes, long long n) 
{
    long long result = -1;
    struct SieveIterator it;

    for (sieve_begin(&it, primes); n != 1; sieve_next(&it)) 
    {
        while (n % *it.current == 0)
        {
            result = *it.current;
            n /= *it.current;
        }
    }

    return result;
}

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 30);

    euler_ok();

    long long max = math_max_prime_factor(&primes, 600851475143ll);

    return euler_submit(3, max, start);
}
