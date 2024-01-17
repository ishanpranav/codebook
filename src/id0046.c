// Licensed under the MIT License.

// Goldbach's Other Conjecture

#include "../lib/euler.h"
#include "../lib/prime_list.h"

bool math_is_goldbach_other_conjecture(long n, PrimeList primes)
{
    long m;

    for (long i = 0; (m = 2 * i * i) < n; i++)
    {
        if (prime_list_is_prime(primes, n - m))
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    struct PrimeList primes;
    clock_t start = clock();
    Exception ex = prime_list(&primes, 2);

    euler_ok();

    long n;

    for (n = 9; ; n += 2)
    {
        if (prime_list_is_prime(&primes, n))
        {
            continue;
        }

        if (!math_is_goldbach_other_conjecture(n, &primes))
        {
            break;
        }
    }

    return euler_submit(46, n, start);
}
