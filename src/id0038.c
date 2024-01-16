// Licensed under the MIT License.

// Pandigital Multiples

#include <math.h>
#include "../lib/euler.h"
#include "../lib/list.h"

int main(void)
{
    long max = 918273645l;
    long second[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    struct List digits;
    struct List pandigital;
    clock_t start = clock();

    list(&digits, 9);
    list_from_array(&pandigital, second, 9);

    for (int i = 2; i < 10000; i++)
    {
        list_clear(&digits);

        for (int j = 1; digits.end - digits.begin < 9; j++)
        {
            char str[11];
            long product = i * j;

            sprintf(str, "%ld", product);

            for (char* p = str; *p; p++)
            {
                Exception ex = list_add(&digits, *p - '0');

                euler_ok();
            }
        }

        long long n = 0;

        for (long* it = digits.begin; it < digits.end; it++)
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

    return euler_submit(38, max, start);
}
