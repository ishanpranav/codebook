// Licensed under the MIT License.

// Coin Partitions

#include "../lib/euler.h"
#include "../lib/partition.h"
#include "../lib/sieve.h"
#define MAX_SEARCH 100000l

int main(void)
{
    long long term = -1;
    clock_t start = clock();

    long long* partitions = mod_partition_range(MAX_SEARCH, 1000000l);

    euler_assert(partitions);

    for (long n = 0; n < MAX_SEARCH; n++)
    {
        if (!partitions[n])
        {
            term = n;

            break;
        }
    }

    free(partitions);

    return euler_submit(78, term, start);
}
