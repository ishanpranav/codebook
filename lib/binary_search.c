// Licensed under the MIT License.

#include <stdlib.h>
#include "binary_search.h"

Object binary_search_min(
    Object min,
    Array items,
    size_t length,
    size_t itemSize,
    Comparer comparer)
{
    if (!length)
    {
        return NULL;
    }

    char* buffer = items;
    size_t left = 0;
    size_t right = length - 1;

    while (left < right)
    {
        size_t index = left + (right - left) / 2;
        int comparison = comparer(buffer + index * itemSize, min);

        if (comparison < 0)
        {
            left = index + 1;
        }
        else if (comparison > 0)
        {
            right = index;
        }
        else
        {
            return buffer + index * itemSize;
        }
    }

    return buffer + right * itemSize;
}

size_t binary_search_rank(
    Object max,
    Array items,
    size_t length,
    size_t itemSize,
    Comparer comparer)
{
    if (!length)
    {
        return 0;
    }

    char* buffer = items;
    size_t left = 0;
    size_t right = length - 1;
    size_t result = 0;

    while (left <= right)
    {
        size_t index = left + (right - left) / 2;

        if (comparer(buffer + index * itemSize, max) < 0)
        {
            result = index + 1;
            left = index + 1;
        }
        else
        {
            right = index - 1;
        }
    }

    return result;
}
