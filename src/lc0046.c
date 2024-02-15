// Licensed under the MIT License.

// Permutations

#include <string.h>
#include "../lib/list.h"
#include "../lib/permutation_iterator.h"
#include "../lib/euler.h"

int** permute(int items[], int length, int* returnSize, int** returnColumnSizes)
{
    struct List results;
    struct PermutationIterator it;

    euler_ok(list(&results, sizeof(int*), 0));
    qsort(items, length, sizeof * items, int_comparer);

    for (permutation_begin(&it, items, length, sizeof * items, int_comparer);
        !it.end;
        permutation_next(&it))
    {
        size_t size = length * sizeof * items;
        int* item = malloc(size);

        euler_assert(item);
        memcpy(item, items, size);
        euler_ok(list_add(&results, &item));
    }
    
    *returnSize = results.count;
    *returnColumnSizes = malloc(results.count * sizeof ** returnColumnSizes);
    
    euler_assert(*returnColumnSizes);

    for (size_t i = 0; i < results.count; i++)
    {
        returnColumnSizes[0][i] = length;
    }

    return results.items;
}
