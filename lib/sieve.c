// Licensed under the MIT License.

#include <math.h>
#include "binary_search.h"
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

        Exception ex = list_add(&instance->primes, &m);

        if (ex)
        {
            return ex;
        }
    }

    instance->max = max;

    return 0;
}

static void sieve_next_impl(SieveIterator iterator)
{
    if (iterator->index + 1 == iterator->values->primes.count)
    {
        if (sieve_extend(iterator->values, iterator->values->max * 2))
        {
            iterator->index = 0;

            return;
        }
    }

    iterator->index++;
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

    ex = list(&instance->primes, sizeof(long long), 0);

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

long long sieve_prime(Sieve instance, size_t n)
{
    return ((long long*)instance->primes.items)[n];
}

void sieve_begin(SieveIterator iterator, Sieve values)
{
    iterator->values = values;
    iterator->index = 0;
    iterator->current = 2;
}

void sieve_jump(SieveIterator iterator, long long min)
{
    long long* primes = iterator->values->primes.items;

    if (iterator->values->max > min)
    {
        long long* prime = binary_search_first_after(
            &min,
            primes,
            iterator->values->primes.count,
            sizeof * primes,
            long_long_comparer);

        if (prime)
        {
            iterator->index = 0;
        }
        else
        {
            iterator->index = prime - primes;
        }
    }

    while (primes[iterator->index] < min)
    {
        sieve_next_impl(iterator);

        primes = iterator->values->primes.items;
    }

    iterator->current = primes[iterator->index];
}

void sieve_skip(SieveIterator iterator, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        sieve_next_impl(iterator);
    }

    long long* primes = iterator->values->primes.items;

    iterator->current = primes[iterator->index];
}

void sieve_next(SieveIterator iterator)
{
    sieve_next_impl(iterator);

    long long* primes = iterator->values->primes.items;

    iterator->current = primes[iterator->index];
}

void finalize_sieve(Sieve instance)
{
    finalize_list(&instance->primes);
    finalize_boolean_set(&instance->composites);
}
