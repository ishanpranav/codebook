// Licensed under the MIT License.

// Summation of Primes

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/prime_list.h"

int main(void)
{
    struct List primes;
    clock_t start = clock();
    Exception ex = list(&primes, 0);

    euler_ok();

    ex = prime_list(&primes, 2000000l);

    euler_ok();

    long long sum = 0;

    for (long* it = primes.begin; it < primes.end; it++)
    {
        sum += *it;
    }

    finalize_list(&primes);
    euler_submit(10, sum, start);

    return 0;
}
