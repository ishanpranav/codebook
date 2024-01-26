// Licensed under the MIT License.

// Non-Abundant Sums

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/factor_iterator.h"

bool math_is_abundant_sum(int n, List list, BooleanSet set)
{
    for (long long* it = list->begin; it < list->end; it++)
    {
        if (*it > n)
        {
            return false;
        }

        if (set->begin[n - *it - 2])
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    struct List abundants;
    clock_t start = clock();
    Exception ex = list(&abundants, 0);

    euler_ok();

    struct BooleanSet set;

    ex = boolean_set(&set, 28123 - 2);

    euler_ok();

    struct Sieve primes;

    ex = sieve(&primes, 0);

    euler_ok();

    for (int n = 12; n < 28123; n++)
    {
        if ((factor_divisor_sum(n, &primes) - n) > n)
        {
            set.begin[n - 2] = true;
        }

        if (set.begin[n - 2])
        {
            list_add(&abundants, n);
        }
    }

    long sum = 1;

    for (int n = 2; n < 28123; n++)
    {
        if (!math_is_abundant_sum(n, &abundants, &set))
        {
            sum += n;
        }
    }

    finalize_list(&abundants);
    finalize_boolean_set(&set);
    finalize_sieve(&primes);

    return euler_submit(23, sum, start);
}
