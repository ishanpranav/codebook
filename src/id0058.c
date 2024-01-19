// Licensed under the MIT License.

// Spiral Primes

#include "../lib/euler.h"
#include "../lib/prime_list.h"

int main(void)
{
    long count = 0;
    int length = 1;
    struct PrimeList primes;
    clock_t start = clock();
    Exception ex = prime_list(&primes, 0);

    euler_ok();

    do
    {
        length += 2;

        long loRight = length * length;
        long loLeft = loRight - length + 1;
        long hiLeft = loLeft - length + 1;
        long hiRight = hiLeft - length + 1;

        if (prime_list_is_prime(&primes, loLeft))
        {
            count++;
        }

        if (prime_list_is_prime(&primes, hiLeft))
        {
            count++;
        }

        if (prime_list_is_prime(&primes, hiRight))
        {
            count++;
        }
    }
    while ((double)count / length >= 0.1 * 2);

    finalize_prime_list(&primes);
    
    return euler_submit(58, length, start);
}
