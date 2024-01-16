// Licensed under the MIT License.

// Distinct Powers

#include "../lib/divisor_iterator.h"
#include "../lib/euler.h"
#include "../lib/list.h"

int main(void)
{
    struct List values;
    int exponents[101] = { 0 };
    clock_t start = clock();
    Exception ex = list(&values, 0);

    euler_ok();

    for (int n = 2; n <= 10; n++)
    {
        int exponent = 2;
        int pow = n * n;

        while (pow <= 100)
        {
            if (exponents[pow] < exponent)
            {
                exponents[pow] = exponent;
                ex = list_add(&values, pow);

                euler_ok();
            }

            pow *= n;
            exponent++;
        }
    }

    int count = 0;

    for (long* it = values.begin; it < values.end; it++)
    {
        int exponent = exponents[*it];

        for (int b = 2; b <= 100; b++)
        {
            int n = exponent * b;
            struct DivisorIterator it;

            for (divisor_begin(&it, n); !divisor_end(&it); divisor_next(&it)) 
            {
                if (it.current < exponent && n / it.current <= 100) 
                {
                    count++;

                    break;
                }
            }
        }
    }

    count = 99 * 99 - count;

    finalize_list(&values);

    return euler_submit(29, count, start);
}
