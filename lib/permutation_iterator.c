// Licensed under the MIT license.

#include "euler.h"
#include "permutation_iterator.h"
#include "swap.h"

void permutation_begin(
    PermutationIterator iterator,
    Array items,
    size_t itemSize,
    size_t length,
    Comparer itemComparer)
{
    iterator->items = items;
    iterator->itemSize = itemSize;
    iterator->length = length;
    iterator->itemComparer = itemComparer;
    iterator->end = !length;
}

void permutation_next(PermutationIterator iterator)
{
    char* begin = iterator->items;
    size_t i = iterator->length - 1;
    size_t n = iterator->itemSize;
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

    size_t j = iterator->length - 1;

    while (comparer(begin + j * n, begin + (i - 1) * n) <= 0)
    {
        j--;
    }
    
    swap(begin + (i - 1) * n, begin + j * n, n);

    j = iterator->length - 1;
    
    while (i < j) 
    {
        swap(begin + i * n, begin + j * n, n);

        i++;
        j--;
    }

    iterator->end = false;
}

static size_t permutation_count(
    Array items,
    size_t itemSize,
    size_t length,
    Object item,
    EqualityComparer itemComparer)
{
    size_t result = 0;
    char* begin = items;
    char* end = begin + length * itemSize;

    for (char* it = begin; it < end; it += itemSize)
    {
        if (itemComparer(item, it))
        {
            result++;
        }
    }

    return result;
}

bool permutation_test(
    Array left,
    size_t leftLength,
    Array right,
    size_t rightLength,
    size_t itemSize,
    EqualityComparer itemComparer)
{
    if (leftLength != rightLength)
    {
        return false;
    }

    char* leftBegin = left;
    char* leftEnd = leftBegin + leftLength * itemSize;
    char* rightBegin = right;

    while (leftBegin < leftEnd && itemComparer(leftBegin, rightBegin))
    {
        leftBegin += itemSize;
        rightBegin += itemSize;
    }

    for (char* it = leftBegin; it < leftEnd; it += itemSize)
    {
        size_t leftCount = permutation_count(
            left, 
            itemSize, 
            leftLength, 
            it, 
            itemComparer);
        size_t rightCount = permutation_count(
            right, 
            itemSize, 
            rightLength, 
            it, 
            itemComparer);

        if (leftCount != rightCount)
        {
            return false;
        }
    }

    return true;
}
