// Licensed under the MIT License.

// Lexicographic Permutations

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

int main(void)
{
    long values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    struct PermutationIterator it;
    clock_t start = clock();
    
    permutation_begin(&it, values, 10);

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
