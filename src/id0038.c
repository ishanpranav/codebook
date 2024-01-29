// Licensed under the MIT License.

// Pandigital Multiples

#include "../lib/euler.h"
#include "../lib/list.h"

int main(void)
{
    long max = 918273645l;
    struct List digits;
    clock_t start = clock();
    Exception ex = list(&digits, sizeof(int), 9);

    euler_ok();
    
    struct List pandigital;
    
    ex = list(&pandigital, sizeof(int), 9);
    
    euler_ok();

    for (int i = 1; i < 9; i++)
    {
        list_add(&pandigital, &i);
    }

    for (int i = 2; i < 10000; i++)
    {
        list_clear(&digits);

        for (int j = 1; digits.count < 9; j++)
        {
            for (long k = i * j; k; k /= 10)
            {
                int digit = k % 10;

                list_add(&digits, &digit);
            }
        }

        long long n = 0;
        int* begin = digits.items; 
        int* end = begin + digits.count;

        for (int* it = begin; it < end; it++)
        {
            n = n * 10 + *it;
        }

        if (n <= max)
        {
            continue;
        }

        list_sort(&digits, int_comparer);

        if (!list_sequence_equal(&digits, &pandigital, int_equality_comparer))
        {
            continue;
        }

        max = n;
    }

    finalize_list(&digits);
    finalize_list(&pandigital);
    
    return euler_submit(38, max, start);
}
