// Licensed under the MIT License.

// Pandigital Multiples

#include "../lib/euler.h"
#include "../lib/list.h"

int main(void)
{
    long max = 918273645l;
    long long array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    struct List digits;
    clock_t start = clock();
    Exception ex = list(&digits, 0);

    euler_ok();
    
    struct List pandigital;
    
    list_from_array(&pandigital, array, 9);

    for (int i = 2; i < 10000; i++)
    {
        list_clear(&digits);

        for (int j = 1; digits.end - digits.begin < 9; j++)
        {
            for (long k = i * j; k; k /= 10)
            {
                list_add(&digits, k % 10);
            }
        }

        long long n = 0;

        for (long long* it = digits.begin; it < digits.end; it++)
        {
            n = n * 10 + *it;
        }

        if (n <= max)
        {
            continue;
        }

        list_sort(&digits);

        if (!list_equals(&digits, &pandigital))
        {
            continue;
        }

        max = n;
    }

    finalize_list(&digits);
    
    return euler_submit(38, max, start);
}
