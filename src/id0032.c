// Licensed under the MIT License.

// Pandigital Products

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

int main(void)
{
    struct List l;
    struct List discovered;
    struct PermutationIterator it;
    long digits[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    clock_t start = clock();
    Exception ex = list(&discovered, 0);

    euler_ok();

    list_from_array(&l, digits, 9);
    
    for (permutation_begin(&it, &l); !it.end; permutation_next(&it))
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
                    a = 10 * a + it.values->begin[k];
                }

                for (int k = i; k < j; k++)
                {
                    b = 10 * b + it.values->begin[k];
                }

                for (int k = j; k < 9; k++)
                {
                    c = 10 * c + it.values->begin[k];
                }

                long product = a * b;

                if (product > c)
                {
                    break;
                }

                if (product != c || list_contains(&discovered, product))
                {
                    continue;
                }

                list_add(&discovered, product);
            }
        }
    }

    long sum = 0;

    for (long* it = discovered.begin; it < discovered.end; it++)
    {
        sum += *it;
    }

    finalize_list(&discovered);

    return euler_submit(32, sum, start);
}
