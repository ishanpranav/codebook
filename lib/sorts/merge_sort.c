// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "../exception.h"
#include "../sort.h"

void merge_sort(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer)
{
    char* begin = items;
    char* buffer = malloc(count * itemSize);

    if (!buffer)
    {
        qsort(items, count, itemSize, itemComparer);

        return;
    }

    for (size_t size = 1; size < count; size *= 2)
    {
        size_t leftFirst = 0;
        size_t rightLast = 0;
        size_t k = 0;

        while (leftFirst + size < count)
        {
            size_t rightFirst = leftFirst + size;
            size_t leftLast = rightFirst - 1;

            if (leftLast + size < count)
            {
                rightLast = leftLast + size;
            }
            else
            {
                rightLast = count - 1;
            }

            size_t i = leftFirst;
            size_t j = rightFirst;

            while (i <= leftLast && j <= rightLast)
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

            while (i <= leftLast)
            {
                char* p = begin + i * itemSize;

                memcpy(buffer + (k++) * itemSize, p, itemSize);

                i++;
            }

            while (j <= rightLast)
            {
                char* q = begin + j * itemSize;

                memcpy(buffer + (k++) * itemSize, q, itemSize);

                j++;
            }

            leftFirst = rightLast + 1;
        }

        memcpy(begin, buffer, (rightLast + 1) * itemSize);
    }

    free(buffer);
}
