// Licensed under the MIT License.

// Pandigital Prime

#include "../lib/euler.h"
#include "../lib/list.h"
#include "../lib/permutation_iterator.h"
#include "../lib/primality_test.h"

int main(void)
{
    struct List digits;
    clock_t start = clock();

    euler_ok(list(&digits, sizeof(int), 10));

    for (int i = 1; i <= 3; i++)
    {
        euler_ok(list_add(&digits, &i));
    }

    long max = 2143;

    for (int i = 4; i <= 9; i++)
    {
        euler_ok(list_add(&digits, &i));

        struct PermutationIterator it;

        for (permutation_begin(
            &it,
            digits.items,
            digits.count,
            digits.itemSize,
            int_comparer);
            !it.end;
            permutation_next(&it))
        {
            long n = 0;
            int* begin = digits.items;
            int* end = begin + digits.count;

            for (int* p = begin; p < end; p++)
            {
                n = n * 10 + *p;
            }

            if (n > max && miller_rabin_primality_test(n) == PRIMALITY_PRIME)
            {
                max = n;
            }
        }
    }

    finalize_list(&digits);

    return euler_submit(41, max, start);
}
