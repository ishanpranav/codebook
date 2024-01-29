// Licensed under the MIT License.

// Circular Primes

#include <math.h>
#include "../lib/euler.h"
#include "../lib/sieve.h"
#define MAX_SEARCH 1000000l

long rotation_next(long n)
{
    return n / 10 + (n % 10) * pow(10, (int)log10(n));
}

bool math_is_circular_prime(long n, Sieve primes)
{
    for (long k = rotation_next(n); k != n; k = rotation_next(k))
    {
        if (sieve_test(primes, k, NULL) != PRIMALITY_PRIME)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, MAX_SEARCH);

    euler_ok();

    int count = 0;
    long long* begin = primes.primes.items;
    long long* end = begin + primes.primes.count;

    for (long long* it = begin; it < end; it++)
    {
        if (math_is_circular_prime(*it, &primes))
        {
            count++;
        }
    }

    finalize_sieve(&primes);

    return euler_submit(35, count, start);
}
