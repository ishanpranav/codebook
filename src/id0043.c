// Licensed under the MIT License.

// Sub-string Divisiblity

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

bool math_is_substring_divisible(List digits)
{
    int mod[] = { 2, 3, 5, 7, 11, 13, 17 };

    for (int i = 0; i < 7; i++)
    {
        int n = 0;

        for (int j = i + 1; j <= i + 3; j++)
        {
            n = n * 10 + digits->begin[j];
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
    struct List list;
    struct PermutationIterator it;
    long long sum = 0;
    long long digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    clock_t start = clock();

    list_from_array(&list, digits, 10);

    for (permutation_begin(&it, &list); !it.end; permutation_next(&it))
    {
        if (math_is_substring_divisible(&list))
        {
            long long n = 0;

            for (long long* d = it.values->begin; d < it.values->end; d++)
            {
                n = n * 10 + *d;
            }

            sum += n;
        }
    }

    euler_submit(43, sum, start);
}
