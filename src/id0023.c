// Licensed under the MIT License.

// Non-Abundant Sums

#include <stdlib.h>
#include "../lib/divisor_iterator.h"
#include "../lib/euler.h"

bool math_is_abundant_sum(int n, int* begin, int* end, bool* set)
{
    for (int* it = begin; it < end; it++)
    {
        if (*it > n)
        {
            return false;
        }
        
        if (set[n - *it - 2])
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    clock_t start = clock();
    int* begin = calloc(28123 - 2, sizeof * begin);

    if (!begin)
    {
        euler_throw("Out of memory");
    }

    bool* set = calloc(28123 - 2, sizeof * set);

    if (!set)
    {
        euler_throw("Out of memory");
    }

    int* end = begin;

    for (int n = 12; n < 28123; n++)
    {
        set[n - 2] = divisor_sum(n) > n;

        if (set[n - 2])
        {
            *end = n;
            end++;
        }
    }

    long sum = 1;

    for (int n = 2; n < 28123; n++)
    {
        if (!math_is_abundant_sum(n, begin, end, set))
        {
            sum += n;
        }
    }

    free(set);
    free(begin);

    return euler_submit(23, sum, start);
}
