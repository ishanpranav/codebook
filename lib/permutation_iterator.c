// Licensed under the MIT license.

#include "euler_swap.h"
#include "permutation_iterator.h"

void permutation_begin(PermutationIterator iterator, List values)
{
    iterator->end = values->begin != values->end;
    iterator->values = values;
}

void permutation_next(PermutationIterator iterator)
{
    long* last = iterator->values->end - 1;

    while (last > iterator->values->begin && last[-1] >= *last)
    {
        last--;
    }

    if (last > iterator->values->begin)
    {
        long* p = iterator->values->end - 1;

        while (p > last && *p <= last[-1])
        {
            p--;
        }

        euler_swap(last - 1, p);
    }

    size_t max = (iterator->values->end - last) / 2;

    for (size_t i = 0; i < max; i++)
    {
        euler_swap(last + i, iterator->values->end - i - 1);
    }

    iterator->end = last != iterator->values->begin;
}
