// Licensed under the MIT License.

// Prime Power Triples

#include <math.h>
#include "../lib/euler.h"
#include "../lib/hash_set.h"
#include "../lib/sieve.h"

int main(void)
{
    struct HashSet sums;
    struct Sieve primes;
    clock_t start = clock();
    long sqrtMax = sqrt(50000000l);
    long cbrtMax = cbrt(50000000l);
    long maxPowFourth = pow(50000000l, 0.25);

    euler_ok(hash_set(
        &sums, 
        sizeof(long long), 
        0,
        long_long_equality_comparer, 
        long_long_hash));
    euler_ok(sieve(&primes, sqrtMax));

    long long* begin = primes.primes.items;
    long long* end = begin + primes.primes.count;

    for (long long* p = begin; p < end && *p < sqrtMax; p++)
    {
        for (long long* q = begin; q < end && *q < cbrtMax; q++)
        {
            for (long long* r = begin; r < end && *r < maxPowFourth; r++)
            {
                long long sum = *p * *p + *q * *q * *q + pow(*r, 4);

                if (sum >= 50000000l)
                {
                    break;
                }

                euler_ok(hash_set_add(&sums, &sum, NULL));
            }
        }
    }

    size_t count = sums.count;

    finalize_hash_set(&sums);
    finalize_sieve(&primes);

    return euler_submit(86, count, start);
}
