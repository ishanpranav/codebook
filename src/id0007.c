// Licensed under the MIT License.

// 10001st Prime

#include <math.h>
#include <stdlib.h>
#include "lib/euler.h"

long math_max_prime(int k)
{
    double logK = log(k);
    
    return ceil(k * logK + k * log(logK));
}

int main(void)
{
    clock_t start = clock();
    long max = math_max_prime(10001);
    long* primes = malloc((max - 2) * sizeof * primes);

    if (!primes || math_get_primes(max, primes) < 0)
    {
        euler_throw("Out of memory");
    }
    
    euler_submit(7, primes[10000], start);
    free(primes);

    return 0;
}
