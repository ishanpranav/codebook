// Licensed under the MIT License.

#include "../sort.h"
#include "../swap.h"

void selection_sort(
    Array items, 
    size_t count, 
    size_t itemSize, 
    Comparer itemComparer)
{
    char* begin = items;

    for (size_t i = 0; i < count - 1; i++)
    {
        size_t min = i;

        for (size_t j = i + 1; j < count; j++)
        {
            if (itemComparer(begin + j * itemSize, begin + min * itemSize) < 0)
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(begin + min * itemSize, begin + i * itemSize, itemSize);
        }
    }
}
