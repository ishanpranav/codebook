// Licensed under the MIT License.

// Summation of Primes

#include "lib/euler.h"
#include "lib/prime_set.h"

int main(void)
{
    clock_t start = clock();
    struct PrimeSet primes;

    if (!prime_set(&primes, 2000000l))
    {
        euler_throw("Out of memory\n");
    }

    long long sum = 0;
    struct PrimeSetIterator iter;

    for (prime_set_begin(&primes, &iter); 
        !prime_set_end(&iter);
        prime_set_next(&iter))
    {
        sum += iter.current;
    }

    euler_submit(10, sum, start);

    return 0;
}
