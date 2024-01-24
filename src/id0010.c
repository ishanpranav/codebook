// Licensed under the MIT License.

// Summation of Primes

#include "../lib/euler.h"
#include "../lib/sieve.h"

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 2000000l);

    euler_ok();

    long long sum = list_sum(&primes.primes);

    finalize_sieve(&primes);
    euler_submit(10, sum, start);

    return 0;
}
