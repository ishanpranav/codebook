// Licensed under the MIT License.

// Summation of Primes

#include "../lib/euler.h"
#include "../lib/sieve.h"

int main(void)
{
    long long sum = 0;
    struct Sieve primes;
    clock_t start = clock();
    
    euler_ok(sieve(&primes, 2000000l));

    long long* begin = primes.primes.items;
    long long* end = begin + primes.primes.count;
    
    for (long long* it = begin; it < end && *it < 2000000l; it++)
    {
        sum += *it;
    }
    
    finalize_sieve(&primes);
    
    return euler_submit(10, sum, start);
}
