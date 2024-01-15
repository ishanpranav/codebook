// Licensed under the MIT License.

// Circular Primes

#include <math.h>
#include "../lib/euler.h"
#include "../lib/prime_list.h"

long rotation_next(long n)
{
    return n / 10 + (n % 10) * pow(10, (int)log10(n));
}

bool math_is_circular_prime(long n, PrimeList primes)
{
    for (long k = rotation_next(n); k != n; k = rotation_next(k))
    {
        if (!prime_list_is_prime(primes, k))
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    struct PrimeList primes;
    clock_t start = clock();
    Exception ex = prime_list(&primes, 1000000l);

    euler_ok();

    int count = 0;

    for (long* p = primes.primes.begin; p < primes.primes.end; p++)
    {
        if (math_is_circular_prime(*p, &primes))
        {
            count++;
        }
    }

    finalize_prime_list(&primes);

    return euler_submit(35, count, start);
}
