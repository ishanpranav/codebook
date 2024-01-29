// Licensed under the MIT License.

// Sub-string Divisiblity

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

static bool math_is_substring_divisible(List digits)
{
    int* begin = digits->items;
    int mod[] = { 2, 3, 5, 7, 11, 13, 17 };

    for (int i = 0; i < 7; i++)
    {
        int n = 0;

        for (int j = i + 1; j <= i + 3; j++)
        {
            n = n * 10 + begin[j];
        }

        if (n % mod[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    struct List digits;
    struct PermutationIterator it;
    long long sum = 0;
    clock_t start = clock();
    Exception ex = list(&digits, sizeof(int), 10);

    euler_ok();

    for (int i = 0; i < 10; i++)
    {
        list_add(&digits, &i);
    }

    for (permutation_begin(&it, &digits, int_comparer);
        !it.end;
        permutation_next(&it))
    {
        if (!math_is_substring_divisible(&digits))
        {
            continue;
        }

        long long n = 0;
        int* begin = digits.items;
        int* end = begin + digits.count;

        for (int* p = begin; p < end; p++)
        {
            n = n * 10 + *p;
        }

        sum += n;
    }

    finalize_list(&digits);
    
    return euler_submit(43, sum, start);
}
