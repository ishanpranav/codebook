// Licensed under the MIT License.

// Reciprocal Cycles

#include <stdlib.h>
#include "../lib/divisor_iterator.h"
#include "../lib/euler.h"
#include "../lib/prime_list.h"

bool math_is_prime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }

    struct DivisorIterator it;
    
    divisor_begin(&it, n);
    divisor_next(&it);

    return divisor_end(&it);
}

int main(void)
{
    struct List primes;
    clock_t start = clock();
    Exception ex = list(&primes, 0);

    euler_ok();

    ex = prime_list(&primes, 1001);
    
    euler_ok();

    int maxA = 0;
    int maxB = 0;
    int maxN = 0;

    for (int a = -999; a < 1000; a += 2)
    {
        for (long* b = primes.begin; b < primes.end; b++)
        {
            int n = 0;

            while (math_is_prime(labs(n * (n + a) + *b)))
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

    finalize_list(&primes);

    int product = maxA * maxB;
    
    return euler_submit(27, product, start);
}
