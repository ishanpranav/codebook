// Licensed under the MIT License.

// Magic 5-gon Ring

#include <math.h>
#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

int main(void)
{
    long long max = 0;
    long long r[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct List l;
    struct PermutationIterator it;
    clock_t start = clock();

    list_from_array(&l, r, 10);

    for (permutation_begin(&it, &l); !it.end; permutation_next(&it))
    {
        if (r[0] > r[3] || r[0] > r[5] || r[0] > r[7] || r[0] > r[9] ||
            (r[3] != 10 && r[5] != 10 && r[7] != 10 && r[9] != 10))
        {
            continue;
        }

        int sum = r[0] + r[1] + r[2];

        if (r[2] + r[3] + r[4] != sum || r[4] + r[5] + r[6] != sum ||
            r[6] + r[7] + r[8] != sum || r[8] + r[9] + r[1] != sum)
        {
            continue;
        }
        
        long long value = math_concat(r[0], r[1]);

        value = math_concat(value, r[2]);

        value = math_concat(value, r[3]);
        value = math_concat(value, r[2]);
        value = math_concat(value, r[4]);
        
        value = math_concat(value, r[5]);
        value = math_concat(value, r[4]);
        value = math_concat(value, r[6]);
        
        value = math_concat(value, r[7]);
        value = math_concat(value, r[6]);
        value = math_concat(value, r[8]);

        value = math_concat(value, r[9]);
        value = math_concat(value, r[8]);
        value = math_concat(value, r[1]);

        if (value > max)
        {
            max = value;
        }
    }

    return euler_submit(68, max, start);
}
