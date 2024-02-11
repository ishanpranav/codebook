// Licensed under the MIT License.

// Distinct Powers

#include <math.h>
#include "../lib/divisor_iterator.h"
#include "../lib/euler.h"
#include "../lib/hash_set.h"

int main(void)
{
    struct HashSet values;
    clock_t start = clock();

    euler_ok(hash_set(
        &values,
        sizeof(double),
        0,
        double_equality_comparer,
        djb2_hash));

    for (int a = 2; a <= 100; a++)
    {
        for (int b = 2; b <= 100; b++)
        {
            double result = pow(a, b);

            euler_ok(hash_set_add(&values, &result, NULL));
        }
    }

    size_t count = values.count;

    finalize_hash_set(&values);

    return euler_submit(29, count, start);
}
