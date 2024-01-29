// Licensed under the MIT License.

// Lexicographic Permutations

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

int main(void)
{
    struct List digits;
    struct PermutationIterator it;
    clock_t start = clock();
    Exception ex = list(&digits, sizeof(int), 10);

    euler_ok();

    for (int i = 0; i < 10; i++)
    {
        list_add(&digits, &i);
    }

    permutation_begin(&it, &digits, int_comparer);

    for (long i = 0; i < 999999l; i++)
    {
        permutation_next(&it);
    }

    int* begin = it.values->items;
    long long result = 0;

    for (int i = 0; i < 10; i++)
    {
        result = result * 10 + begin[i];
    }

    finalize_list(&digits);

    return euler_submit(24, result, start);
}
