// Licensed under the MIT License.

// 10001st Prime

#include <math.h>
#include "../lib/euler.h"
#include "../lib/sieve.h"

long math_max_prime(int k)
{
    double logK = log(k);

    return ceil(k * logK + k * log(logK));
}

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    long max = math_max_prime(10001);
    Exception ex = sieve(&primes, max);

    euler_ok();

    long p = primes.primes.begin[10000];

    finalize_sieve(&primes);
    euler_submit(7, p, start);
    
    return 0;
}
