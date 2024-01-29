// Licensed under the MIT License.

// Pandigital Products

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

int main(void)
{
    struct List set;
    struct PermutationIterator it;
    clock_t start = clock();
    Exception ex = list(&set, sizeof(long), 0);

    euler_ok();

    struct List digits;

    ex = list(&digits, sizeof(int), 9);

    euler_ok();

    for (int i = 1; i <= 9; i++)
    {
        list_add(&digits, &i);
    }

    int* digitsBegin = digits.items;

    for (permutation_begin(&it, &digits, int_comparer);
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
                    a = 10 * a + digitsBegin[k];
                }

                for (int k = i; k < j; k++)
                {
                    b = 10 * b + digitsBegin[k];
                }

                for (int k = j; k < 9; k++)
                {
                    c = 10 * c + digitsBegin[k];
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
                    list_add(&set, &product);
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
    
    finalize_list(&digits);
    finalize_list(&set);

    return euler_submit(32, sum, start);
}
