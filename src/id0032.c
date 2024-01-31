// Licensed under the MIT License.

// Pandigital Products

#include "../lib/euler.h"
#include "../lib/list.h"
#include "../lib/permutation_iterator.h"

int main(void)
{
    struct List set;
    struct PermutationIterator it;
    int digits[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    clock_t start = clock();

    euler_ok(list(&set, sizeof(long), 0));

    for (permutation_begin(&it, digits, sizeof * digits, 9, int_comparer);
        !it.end;
        permutation_next(&it))
    {
        for (int i = 1; i < 7; i++)
        {
            for (int j = i + 1; j < 8; j++)
            {
                long a = 0;
                long b = 0;
                long c = 0;
                
                for (int k = 0; k < i; k++)
                {
                    a = 10 * a + digits[k];
                }

                for (int k = i; k < j; k++)
                {
                    b = 10 * b + digits[k];
                }

                for (int k = j; k < 9; k++)
                {
                    c = 10 * c + digits[k];
                }

                long product = a * b;

                if (product > c)
                {
                    break;
                }

                if (product != c)
                {
                    continue;
                }

                if (!list_contains(&set, &product, long_equality_comparer))
                {
                    euler_ok(list_add(&set, &product));
                }
            }
        }
    }

    long long sum = 0;
    long* setBegin = set.items;
    long* setEnd = setBegin + set.count;

    for (long* it = setBegin; it < setEnd; it++)
    {
        sum += *it;
    }
    
    finalize_list(&set);

    return euler_submit(32, sum, start);
}
