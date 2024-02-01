// Licensed under the MIT License.

#include <stdlib.h>
#include "../exception.h"
#include "../merge.h"
#include "../sort.h"

static Exception merge_sort_impl(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer)
{
    for (size_t length = 1; length < count; length *= 2)
    {
        for (size_t left = 0; left < count - 1; left += length * 2)
        {
            size_t mid = left + length - 1;

            if (count <= mid)
            {
                mid = count - 1;
            }

            size_t right = left + (length * 2) - 1;

            if (count <= right)
            {
                right = count - 1;
            }

            size_t leftLength = mid - left + 1;
            size_t rightLength = right - mid;
            char* leftBuffer = malloc(leftLength * itemSize);

            if (!leftBuffer)
            {
                return EXCEPTION_OUT_OF_MEMORY;
            }

            char* rightBuffer = malloc(rightLength * itemSize);

            if (!rightBuffer)
            {
                free(leftBuffer);

                return EXCEPTION_OUT_OF_MEMORY;
            }

            merge(
                items, 
                leftBuffer, 
                leftLength, 
                rightBuffer, 
                rightLength, 
                itemSize, 
                itemComparer);
            free(leftBuffer);
            free(rightBuffer);
        }
    }

    return 0;
}

void merge_sort(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer)
{
    if (merge_sort_impl(items, count, itemSize, itemComparer))
    {

    }
}
