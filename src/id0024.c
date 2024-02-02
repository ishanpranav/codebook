// Licensed under the MIT License.

// Lexicographic Permutations

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

int main(void)
{
    struct PermutationIterator it;
    int digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    clock_t start = clock();

    permutation_begin(&it, digits, 10, sizeof * digits, int_comparer);

    for (long i = 0; i < 999999l; i++)
    {
        permutation_next(&it);
    }

    long long result = 0;

    for (int i = 0; i < 10; i++)
    {
        result = result * 10 + digits[i];
    }

    return euler_submit(24, result, start);
}
