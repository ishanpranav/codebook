// Licensed under the MIT License.

#include <math.h>
#include "divisor_iterator.h"
#include "sieve_iterator.h"

static Exception sieve_extend(Sieve instance, long long max)
{
    Exception ex = boolean_set_ensure_capacity(&instance->composites, max - 2);

    if (ex)
    {
        return ex;
    }
    
    long long end = sqrt(max);

    for (long long m = 2; m <= end; m++)
    {
        if (instance->composites.begin[m - 2])
        {
            continue;
        }

        for (long long n = m * m; n < max; n += m)
        {
            instance->composites.begin[n - 2] = true;
        }
    }

    for (long long m = instance->max; m < max; m++)
    {
        if (instance->composites.begin[m - 2])
        {
            continue;
        }

        Exception ex = list_add(&instance->primes, m);

        if (ex)
        {
            return ex;
        }
    }

    instance->max = max;

    return ex;
}

Exception sieve(Sieve instance, long long max)
{
    if (max < 12)
    {
        max = 12;
    }

    Exception ex = boolean_set(&instance->composites, max - 2);

    if (ex)
    {
        return ex;
    }

    ex = list(&instance->primes, 0);

    if (ex)
    {
        finalize_boolean_set(&instance->composites);

        return ex;
    }

    instance->max = 2;

    ex = sieve_extend(instance, max);

    if (ex)
    {
        finalize_boolean_set(&instance->composites);
        finalize_list(&instance->primes);

        return ex;
    }

    return 0;
}

void sieve_begin(SieveIterator iterator, Sieve values)
{
    iterator->values = values;
    iterator->current = values->primes.begin;
}

void sieve_skip(SieveIterator iterator, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        sieve_next(iterator);
    }
}

void sieve_next(SieveIterator iterator)
{
    long long* end = iterator->values->primes.end;

    if (iterator->current + 1 == end)
    {
        size_t length = end - iterator->values->primes.begin;

        if (sieve_extend(iterator->values, iterator->values->max * 2))
        {
            iterator->current = iterator->values->primes.begin;

            return;
        }

        iterator->current = iterator->values->primes.begin + length - 1;
    }

    iterator->current++;
}

Primality sieve_test(Sieve instance, long long n, PrimalityTest fallback)
{
    if (n < 2 || n >= instance->max)
    {
        if (fallback)
        {
            return fallback(n);
        }

        return PRIMALITY_UNKNOWN;
    }

    if (instance->composites.begin[n - 2])
    {
        return PRIMALITY_COMPOSITE;
    }

    return PRIMALITY_PRIME;
}

void finalize_sieve(Sieve instance)
{
    finalize_list(&instance->primes);
    finalize_boolean_set(&instance->composites);
}
