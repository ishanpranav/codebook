// Licensed under the MIT License.

#include "../equality_comparer.h"

bool char_equality_comparer(Object left, Object right)
{
    return *(char*)left == *(char*)right;
}
