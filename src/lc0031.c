// Licensed under the MIT License.

// Next Permutation

#include <stdlib.h>
#include "../lib/permutation_iterator.h"

void nextPermutation(int items[], int length) 
{
    struct PermutationIterator it;

    permutation_begin(&it, items, length, sizeof * items, int_comparer);
    permutation_next(&it);
    
    if (it.end)
    {
        qsort(items, length, sizeof * items, int_comparer);
    }
}
