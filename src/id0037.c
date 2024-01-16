// Licensed under the MIT License.

// Truncatable Primes

#include <math.h>
#include "../lib/euler.h"
#include "../lib/prime_list.h"

int main(void)
{
    long sum = 0;
    int count = 0;
    struct PrimeList primes;
    clock_t start = clock();
    Exception ex = prime_list(&primes, 739399l);

    euler_ok();

    for (long* it = primes.primes.begin + 4; it < primes.primes.end; it++)
    {
        if (count == 11)
        {
            break;
        }

        long right = *it;

        while (right && prime_list_is_prime(&primes, right))
        {
            right /= 10;
        }

        if (right)
        {
            continue;
        }

        long left = *it;
        long orderOfMagnitude = pow(10, (int)log10(left));

        while (left && prime_list_is_prime(&primes, left))
        {
            left %= orderOfMagnitude;
            orderOfMagnitude /= 10;
        }

        if (left)
        {
            continue;
        }

        sum += *it;
        count++;
    }

    finalize_prime_list(&primes);
    
    return euler_submit(37, sum, start);
}
