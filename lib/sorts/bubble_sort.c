// Licensed under the MIT License.

#include "../sort.h"
#include "../swap.h"

void bubble_sort(
    Array items, 
    size_t count, 
    size_t itemSize, 
    Comparer itemComparer)
{
    char* begin = items;

    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = 0; j < count - i - 1; j++)
        {
            char* q = begin + j * itemSize;

            if (itemComparer(q, q + itemSize) > 0)
            {
                swap(q, q + itemSize, itemSize);
            }
        }
    }
}
