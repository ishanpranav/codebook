// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "../sort.h"

void insertion_sort(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer)
{
    char* begin = items;
    void* swap = malloc(itemSize);

    if (!swap)
    {
        selection_sort(items, count, itemSize, itemComparer);

        return;
    }

    for (size_t i = 1; i < count; i++)
    {
        char* p = begin + i * itemSize;
        size_t j = i;

        while (j-- > 0)
        {
            if (itemComparer(p, begin + j * itemSize) >= 0)
            {
                break;
            }
        }

        j++;

        char* q = begin + j * itemSize; 

        memcpy(swap, p, itemSize);
        memmove(q + itemSize, q, (i - j) * itemSize);
        memcpy(q, swap, itemSize);
    }

    free(swap);
}
