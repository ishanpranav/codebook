// Licensed under the MIT License.

// Permutation Sequence

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

String getPermutation(int n, int k)
{
    struct PermutationIterator it;
    String sequence = string(n);

    euler_assert(sequence);

    for (int i = 0; i < n; i++)
    {
        sequence[i] = (i + 1) + '0';
    }

    sequence[n] = '\0';
    k--;

    qsort(sequence, n, sizeof * sequence, char_comparer);

    for (permutation_begin(&it, sequence, sizeof * sequence, n, char_comparer); 
        k > 0;
        permutation_next(&it))
    {
        k--;
    }

    return sequence;
}
