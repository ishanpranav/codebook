// Licensed under the MIT license.

#include "euler_swap.h"
#include "permutation_iterator.h"

void permutation_begin(
    PermutationIterator iterator,
    long* values,
    size_t length)
{
    iterator->end = false;
    iterator->length = length;
    iterator->set = values;
}

void permutation_next(PermutationIterator iterator)
{
    size_t last = iterator->length - 1;

    while (last > 0 && iterator->set[last - 1] >= iterator->set[last])
    {
        last--;
    }

    if (last > 0)
    {
        size_t index = iterator->length - 1;

        while (index > last && iterator->set[index] <= iterator->set[last - 1])
        {
            index--;
        }

        euler_swap(iterator->set + last - 1, iterator->set + index);
    }

    size_t max = (iterator->length - last) / 2;

    for (size_t index = 0; index < max; index++)
    {
        long* p = iterator->set + last + index;
        long* q = iterator->set + iterator->length - 1 - index;

        euler_swap(p, q);
    }

    iterator->end = !last;
}
