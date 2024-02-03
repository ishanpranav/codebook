// Licensed under the MIT License.

// Counting Summations

#include "../lib/euler.h"
#include "../lib/partition.h"

int main(void)
{
    clock_t start = clock();
    long long* partitions = mod_partition_range(101, 10000000);

    euler_assert(partitions);

    long long result = partitions[100] - 1;

    free(partitions);

    return euler_submit(76, result, start);
}
