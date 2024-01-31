// Licensed under the MIT License.

// Non-Abundant Sums

#include "../lib/euler.h"
#include "../lib/factor_iterator.h"

static bool math_is_abundant_sum(int n, List list, BooleanSet set)
{
    int* begin = list->items;
    int* end = begin + list->count;

    for (int* it = begin; it < end; it++)
    {
        if (*it > n)
        {
            return false;
        }

        if (set->begin[n - *it])
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    long sum = 1;
    struct Sieve primes;
    struct List abundants;
    struct BooleanSet set;
    clock_t start = clock();

    euler_ok(list(&abundants, sizeof(int), 0));
    euler_ok(boolean_set(&set, 28123));
    euler_ok(sieve(&primes, 0));

    for (int n = 12; n < 28123; n++)
    {
        if ((factor_divisor_sum(n, &primes) - n) > n)
        {
            set.begin[n] = true;
        }

        if (set.begin[n])
        {
            euler_ok(list_add(&abundants, &n));
        }
    }

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
