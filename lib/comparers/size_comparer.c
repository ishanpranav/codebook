// Licensed under the MIT License.

#include <stddef.h>

int size_comparer(const void* left, const void* right)
{
    size_t leftValue = *((const size_t*)left);
    size_t rightValue = *((const size_t*)right);

    if (leftValue < rightValue)
    {
        return -1;
    }

    if (leftValue > rightValue)
    {
        return 1;
    }

    return 0;
}
