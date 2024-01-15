// Licensed under the MIT License.

#include <math.h>
#include <stdbool.h>
#include "divisor_iterator.h"
#include "prime_list.h"

Exception prime_list(PrimeList instance, long max)
{
    Exception ex = boolean_set(&instance->composites, max - 2);

    if (ex)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    long end = sqrt(max);

    for (long m = 2; m <= end; m++)
    {
        if (instance->composites.begin[m - 2])
        {
            continue;
        }

        for (long n = m * m; n < max; n += m)
        {
            instance->composites.begin[n - 2] = true;
        }
    }

    ex = list(&instance->primes, 0);

    if (ex)
    {
        finalize_boolean_set(&instance->composites);

        return ex;
    }

    for (long i = 0; i < max - 2; i++)
    {
        if (instance->composites.begin[i])
        {
            continue;
        }

        ex = list_add(&instance->primes, i + 2);

        if (ex)
        {
            finalize_list(&instance->primes);
            finalize_boolean_set(&instance->composites);

            return ex;
        }
    }

    return ex;
}

bool prime_list_is_prime(PrimeList instance, long n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }

    if (n < instance->max && !instance->composites.begin[n])
    {
        return true;
    }

    struct DivisorIterator it;

    divisor_begin(&it, n);
    divisor_next(&it);

    return divisor_end(&it);
}

void finalize_prime_list(PrimeList instance)
{
    finalize_list(&instance->primes);
    finalize_boolean_set(&instance->composites);
}
