// Licensed under the MIT License.

#include "../comparer.h"

int int_comparer(const void* left, const void* right)
{
    return *(const int*)left - *(const int*)right;
}
