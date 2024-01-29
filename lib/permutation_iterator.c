// Licensed under the MIT license.

#include "euler.h"
#include "permutation_iterator.h"
#include "swap.h"

void permutation_begin(
    PermutationIterator iterator,
    List values,
    Comparer itemComparer)
{
    iterator->end = false;
    iterator->values = values;
    iterator->itemComparer = itemComparer;
}

void permutation_next(PermutationIterator iterator)
{
    char* begin = iterator->values->items;
    size_t count = iterator->values->count;

    if (!count)
    {
        iterator->end = true;

        return;
    }

    size_t i = count - 1;
    size_t n = iterator->values->itemSize;
    Comparer comparer = iterator->itemComparer;

    while (i > 0 && comparer(begin + (i - 1) * n, begin + i * n) >= 0)
    {
        i--;
    }

    if (i == 0)
    {
        iterator->end = true;

        return;
    }

    size_t j = count - 1;

    while (comparer(begin + j * n, begin + (i - 1) * n) <= 0)
    {
        j--;
    }
    
    swap(begin + (i - 1) * n, begin + j * n, n);

    j = count - 1;
    
    while (i < j) 
    {
        swap(begin + i * n, begin + j * n, n);

        i++;
        j--;
    }

    iterator->end = false;
}

static size_t permutation_count(
    List list,
    Object item,
    EqualityComparer itemComparer)
{
    size_t result = 0;

    char* begin = list->items;
    char* end = begin + list->count * list->itemSize;

    for (char* it = begin; it < end; it += list->itemSize)
    {
        if (itemComparer(item, it))
        {
            result++;
        }
    }

    return result;
}

bool permutation_test(List left, List right, EqualityComparer itemComparer)
{
    size_t itemSize = left->itemSize;

    if (right->itemSize != itemSize)
    {
        return false;
    }

    size_t count = left->count;

    if (right->count != count)
    {
        return false;
    }

    char* leftBegin = left->items;
    char* leftEnd = leftBegin + count * itemSize;
    char* rightBegin = right->items;

    while (leftBegin < leftEnd && itemComparer(leftBegin, rightBegin) == 0)
    {
        leftBegin += itemSize;
        rightBegin += itemSize;
    }

    for (char* it = leftBegin; it < leftEnd; it += itemSize)
    {
        size_t leftCount = permutation_count(left, it, itemComparer);
        size_t rightCount = permutation_count(right, it, itemComparer);

        if (leftCount != rightCount)
        {
            return false;
        }
    }

    return true;
}
