// Licensed under the MIT License.

// Prime Summations

#include "../lib/euler.h"
#include "../lib/partition.h"
#include "../lib/sieve.h"
#define MAX_SEARCH 100

int main(void)
{
    long long term = -1;
    struct Sieve primes;
    clock_t start = clock();

    euler_ok(sieve(&primes, MAX_SEARCH));

    long long* constraints = primes.primes.items;
    long long* partitions = restricted_partition_range(
        MAX_SEARCH, 
        constraints,
        primes.primes.count);

    euler_assert(partitions);

    for (int n = 0; n < MAX_SEARCH; n++)
    {
        if (partitions[n] > 5000)
        {
            term = n;

            break;
        }
    }

    free(partitions);

    return euler_submit(77, term, start);
}
