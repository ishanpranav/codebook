// Licensed under the MIT License.

// Coin Sums

#include "../lib/euler.h"
#include "../lib/partition.h"

int main(void)
{
    int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    clock_t start = clock();
    long long* partitions = restricted_partition_range(201, coins, 8);

    euler_assert(partitions);

    long long result = partitions[200];

    free(partitions);

    return euler_submit(31, result, start);
}
