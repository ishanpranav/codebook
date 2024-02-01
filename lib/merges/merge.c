// Licensed under the MIT License.

#include <string.h>
#include "../merge.h"

Exception merge(
    Array result,
    Array left,
    size_t leftLength,
    Array right,
    size_t rightLength,
    size_t itemSize,
    Comparer itemComparer)
{
    char* a = left;
    char* b = right;
    char* c = result;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < leftLength && j < rightLength)
    {
        if (itemComparer(a + i * itemSize, b + j * itemSize) >= 0) 
        {
            memcpy(c + (k++) * itemSize, a + (i++) * itemSize, itemSize);
        }
        else
        {
            memcpy(c + (k++) * itemSize, b + (j++) * itemSize, itemSize);
        }
    }

    while (j < rightLength)
    {
        memcpy(c + (k++) * itemSize, b + (j++) * itemSize, itemSize);
    }

    while (i < leftLength)
    {
        memcpy(c + (k++) * itemSize, a + (i++) * itemSize, itemSize);
    }

    return 0;
}
