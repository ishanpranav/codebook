// Licensed under the MIT license.

#include "euler.h"
#include "permutation_iterator.h"
#include "swap.h"

void permutation_begin(PermutationIterator iterator, List values)
{
    iterator->end = false;
    iterator->values = values;
}

void permutation_next(PermutationIterator iterator)
{
    long long* last = iterator->values->end - 1;

    while (last > iterator->values->begin && last[-1] >= *last)
    {
        last--;
    }

    if (last > iterator->values->begin)
    {
        long long* p = iterator->values->end - 1;

        while (p > last && *p <= last[-1])
        {
            p--;
        }

        swap(last - 1, p);
    }

    size_t max = (iterator->values->end - last) / 2;

    for (size_t i = 0; i < max; i++)
    {
        swap(last + i, iterator->values->end - i - 1);
    }

    iterator->end = last == iterator->values->begin;
}

static size_t permutation_count(List list, long long item)
{
    size_t result = 0;

    for (long long* it = list->begin; it < list->end; it++)
    {
        if (item == *it)
        {
            result++;
        }
    }

    return result;
}

bool permutation_test(List left, List right)
{
    long long* leftBegin = left->begin;
    long long* rightBegin = right->begin;

    if (left->end - leftBegin != right->end - rightBegin)
    {
        return false;
    }

    while (leftBegin < left->end && *leftBegin == *rightBegin)
    {
        leftBegin++;
        rightBegin++;
    }

    for (long long* it = leftBegin; it < left->end; it++)
    {
        size_t leftCount = permutation_count(left, *it);
        size_t rightCount = permutation_count(right, *it);

        if (leftCount != rightCount)
        {
            return false;
        }
    }
    
    return true;
}
