#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "prime_set.h"

bool prime_set(PrimeSet instance, long max)
{
    instance->max = max;
    instance->composites = calloc(max - 2, sizeof * instance->composites);

    if (!instance->composites)
    {
        return false;
    }

    double sqrtMax = sqrt(max);

    for (long m = 2; m <= sqrtMax; m++)
    {
        if (instance->composites[m - 2])
        {
            continue;
        }

        for (long n = m * m; n < max; n += m)
        {
            instance->composites[n - 2] = true;
        }
    }

    return true;
}

void prime_set_begin(PrimeSet instance, PrimeSetIterator iterator)
{
    iterator->set = instance;
    iterator->current = 2;
}

bool prime_set_end(PrimeSetIterator iterator)
{
    return iterator->current >= iterator->set->max;
}

void prime_set_next(PrimeSetIterator iterator)
{
    long max = iterator->set->max;
    bool* composites = iterator->set->composites;

    do
    {
        iterator->current++;
    }
    while (iterator->current < max && composites[iterator->current - 2]);
}

void finalize_prime_set(PrimeSet instance)
{
    free(instance->composites);
}
