// Licensed under the MIT License.

#include <math.h>
#include "factor_iterator.h"

void factor_begin(FactorIterator iterator, long long n, Sieve primes)
{
    iterator->remainder = n;
    
    sieve_begin(&iterator->iterator, primes);
    factor_next(iterator);
}

bool factor_end(FactorIterator iterator)
{
    return !iterator->remainder;
}

void factor_next(FactorIterator iterator)
{
    if (iterator->remainder == 1)
    {
        iterator->current = iterator->iterator.current;
        iterator->remainder = 0;
        iterator->exponent = 1;

        return;
    }

    while (iterator->remainder % iterator->iterator.current != 0)
    {
        sieve_next(&iterator->iterator);
    }

    iterator->current = iterator->iterator.current;
    iterator->remainder /= iterator->current;
    iterator->exponent = 1;

    while (iterator->remainder % iterator->current == 0)
    {
        iterator->remainder /= iterator->current;
        iterator->exponent++;
    }
}

int factor_divisor_count(long long n, Sieve primes)
{
    int result = 1;
    struct FactorIterator it;

    for (factor_begin(&it, n, primes); !factor_end(&it); factor_next(&it))
    {
        result *= it.exponent + 1;
    }

    return result;
}

int factor_divisor_sum(long long n, Sieve primes)
{
    int result = 1;
    struct FactorIterator it;

    for (factor_begin(&it, n, primes); !factor_end(&it); factor_next(&it))
    {
        result *= (pow(it.current, it.exponent + 1) - 1) / (it.current - 1);
    }
    
    return result;
}

int factor_sum(long long n, Sieve primes)
{
    long long sum = 0;
    struct FactorIterator it;

    for (factor_begin(&it, n, primes); !factor_end(&it); factor_next(&it))
    {
        sum += it.exponent * it.current;
    }

    return sum;
}
