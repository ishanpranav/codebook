// Licensed under the MIT License.

#include "../equality_comparer.h"

bool int_equality_comparer(Object left, Object right)
{
    return *(int*)left == *(int*)right;
}
