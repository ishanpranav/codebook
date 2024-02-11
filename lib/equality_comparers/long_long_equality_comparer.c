// Licensed under the MIT License.

#include "../equality_comparer.h"

bool long_long_equality_comparer(Object left, Object right)
{
    return *(long long*)left == *(long long*)right;
}
