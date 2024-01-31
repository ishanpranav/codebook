// Licensed under the MIT License.

// Highly Divisible Triangular Number

#include <math.h>
#include "../lib/euler.h"
#include "../lib/factor_iterator.h"

int main(void)
{
    int i = 7;
    long n = 28;
    struct Sieve primes;
    clock_t start = clock();
    
    euler_ok(sieve(&primes, 0));

    while (factor_divisor_count(n, &primes) <= 500)
    {
        i++;
        n = n + i;
    }

    finalize_sieve(&primes);
    
    return euler_submit(12, n, start);
}
