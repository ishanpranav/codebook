// Licensed under the MIT License.

// 10001st Prime

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "euler.h"
#include "prime_set.h"

long math_max_prime(int k)
{
    double logK = log(k);
    
    return ceil(k * logK + k * log(logK));
}

int main(void)
{
    clock_t start = clock();
    struct PrimeSet primes;

    if (!prime_set(&primes, math_max_prime(10001)))
    {
        euler_throw("Out of memory");
    }
    
    struct PrimeSetIterator iter;

    prime_set_begin(&primes, &iter);

    for (int i = 0; i < 10000; i++)
    {
        prime_set_next(&iter);
    }

    euler_submit(7, iter.current, start);
    finalize_prime_set(&primes);

    return 0;
}
