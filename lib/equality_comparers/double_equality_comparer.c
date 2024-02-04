// Licensed under the MIT License.

#include "../equality_comparer.h"

bool double_equality_comparer(Object left, Object right)
{
    return *(double*)left == *(double*)right;
}
