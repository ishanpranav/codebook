// Licensed under the MIT License.

// Distinct Powers

#include <math.h>
#include "../lib/divisor_iterator.h"
#include "../lib/euler.h"
#include "../lib/list.h"

int main(void)
{
    struct List values;
    clock_t start = clock();
    Exception ex = list(&values, sizeof(double), 0);

    euler_ok();

    for (int a = 2; a <= 100; a++)
    {
        for (int b = 2; b <= 100; b++)
        {
            double result = pow(a, b);

            if (!list_contains(&values, &result, double_equality_comparer))
            {
                list_add(&values, &result);
            }
        }
    }

    size_t count = values.count;

    finalize_list(&values);

    return euler_submit(29, count, start);
}
