// Licensed under the MIT License.

// Magic 5-gon Ring

#include <math.h>
#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

int main(void)
{
    long long max = 0;
    long long values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    struct List ring;
    struct PermutationIterator it;
    clock_t start = clock();

    list_from_array(&ring, values, 10);

    for (permutation_begin(&it, &ring); !it.end; permutation_next(&it))
    {
        long long* l = it.values->begin;
        
        if (l[0] > l[3] || l[0] > l[5] || l[0] > l[7] || l[0] > l[9] ||
            (l[3] != 10 && l[5] != 10 && l[7] != 10 && l[9] != 10))
        {
            continue;
        }

        int sum = l[0] + l[1] + l[2];

        if (l[2] + l[3] + l[4] != sum || l[4] + l[5] + l[6] != sum ||
            l[6] + l[7] + l[8] != sum || l[8] + l[9] + l[1] != sum)
        {
            continue;
        }
        
        long long value = math_concat(
            l[0], l[1], l[2], 
            l[3], l[2], l[4], 
            l[5], l[5], l[6],
            l[7], l[6], l[8],
            l[9], l[8], l[1]);

        if (value > max)
        {
            max = value;
        }
    }

    return euler_submit(68, max, start);
}
