// Licensed under the MIT License.

// Lexicographic Permutations

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

int main(void)
{
    long long values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    struct List list;
    struct PermutationIterator it;
    clock_t start = clock();
    
    list_from_array(&list, values, 10);
    permutation_begin(&it, &list);

    for (long i = 0; i < 999999l; i++)
    {
        permutation_next(&it);
    }
    
    long long result = 0;

    for (int i = 0; i < 10; i++)
    {
        result = result * 10 + values[i];
    }

    return euler_submit(24, result, start);
}
