// Licensed under the MIT License.

#include "equality_comparer.h"

bool char_equality_comparer(Object left, Object right)
{
    return *(char*)left == *(char*)right;
}

bool int_equality_comparer(Object left, Object right)
{
    return *(int*)left == *(int*)right;
}

bool long_equality_comparer(Object left, Object right)
{
    return *(long*)left == *(long*)right;
}

bool double_equality_comparer(Object left, Object right)
{
    return *(double*)left == *(double*)right;
}
