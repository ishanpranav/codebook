// Licensed under the MIT License.

#include <stdlib.h>
#include "binary_search.h"

Object binary_search_first_after(
    Object item,
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

        if (comparer(buffer + index * itemSize, item) <= 0)
        {
            left = index + 1;
        }
        else
        {
            right = index - 1;
        }
    }

    return buffer + left * itemSize;
}
