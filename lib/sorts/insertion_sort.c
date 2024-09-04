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
    void* key = malloc(itemSize);

    if (!key)
    {
        selection_sort(items, count, itemSize, itemComparer);

        return;
    }

    for (size_t i = 1; i < count; i++) 
    {
        memcpy(key, begin + i * itemSize, itemSize);

        ptrdiff_t j = i - 1;
        
        while (j >= 0 && itemComparer(begin + j * itemSize, key) > 0)
        {
            j--;
        }

        if (j != i - 1) 
        {
            memmove(
                begin + (j + 2) * itemSize, 
                begin + (j + 1) * itemSize, 
                (i - j - 1) * itemSize);
        }

        memcpy(begin + (j + 1) * itemSize, key, itemSize);
    }

    free(key);
}
