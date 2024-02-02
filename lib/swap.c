// Licensed under the MIT License.

#include "swap.h"

void swap(Object left, Object right, size_t size)
{    
    if (left == right)
    {
        return;
    }
    
    char* p = left;
    char* q = right;
    char swap;

    for (size_t i = 0; i < size; i++)
    {
        swap = p[i];
        p[i] = q[i];
        q[i] = swap;
    }
}
