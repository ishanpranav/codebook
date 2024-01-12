// Licensed under the MIT License.

// 10001st Prime

#include <math.h>
#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/prime_list.h"

long math_max_prime(int k)
{
    double logK = log(k);

    return ceil(k * logK + k * log(logK));
}

int main(void)
{
    struct List primes;
    clock_t start = clock();
    long max = math_max_prime(10001);
    Exception ex = list(&primes, max - 2);

    euler_ok();

    ex = prime_list(&primes, max);

    euler_ok();

    long p = primes.begin[10000];

    finalize_list(&primes);
    euler_submit(7, p, start);
    
    return 0;
}
