// Licensed under the MIT License.

#include "../comparer.h"

int char_comparer(const void* left, const void* right)
{
    return *((const char*)left) - *((const char*)right);
}
