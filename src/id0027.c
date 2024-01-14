// Licensed under the MIT License.

// Quadratic Primes

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/prime_list.h"

int main(void)
{
    struct PrimeList primes;
    clock_t start = clock();
    Exception ex = prime_list(&primes, 1001);
    
    euler_ok();

    int maxA = 0;
    int maxB = 0;
    int maxN = 0;

    for (int a = -999; a < 1000; a += 2)
    {
        for (long* b = primes.primes.begin; b < primes.primes.end; b++)
        {
            int n = 0;

            while (prime_list_is_prime(&primes, labs(n * (n + a) + *b)))
            {
                n++;
            }

            if (n > maxN)
            {
                maxA = a;
                maxB = *b;
                maxN = n;
            }
        }
    }

    finalize_prime_list(&primes);

    int product = maxA * maxB;
    
    return euler_submit(27, product, start);
}
