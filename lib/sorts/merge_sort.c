// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "../exception.h"
#include "../merge.h"
#include "../sort.h"

void merge_sort(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer)
{
    char* begin = items;
    char* buffer = malloc(count * itemSize);

    for (size_t size = 1; size < count; size *= 2)
    {
        size_t leftMin = 0;
        size_t rightMax = 0;
        size_t k = 0;

        while (leftMin + size < count)
        {
            size_t rightMin = leftMin + size;
            size_t leftMax = rightMin - 1;

            if (leftMax + size < count)
            {
                rightMax = leftMax + size;
            }
            else
            {
                rightMax = count - 1;
            }

            size_t i = leftMin;
            size_t j = rightMin;

            while (i <= leftMax && j <= rightMax)
            {
                char* p = begin + i * itemSize;
                char* q = begin + j * itemSize;

                if (itemComparer(p, q) < 0)
                {
                    memcpy(buffer + (k++) * itemSize, p, itemSize);

                    i++;
                }
                else
                {
                    memcpy(buffer + (k++) * itemSize, q, itemSize);

                    j++;
                }
            }

            while (i <= leftMax)
            {
                char* p = begin + i * itemSize;

                memcpy(buffer + (k++) * itemSize, p, itemSize);

                i++;
            }

            while (j <= rightMax)
            {
                char* q = begin + j * itemSize;

                memcpy(buffer + (k++) * itemSize, q, itemSize);

                j++;
            }

            leftMin = rightMax + 1;
        }

        memcpy(begin, buffer, (rightMax + 1) * itemSize);
    }

    free(buffer);
}
