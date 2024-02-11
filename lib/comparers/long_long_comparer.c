// Licensed under the MIT License.

#include "../comparer.h"

int long_long_comparer(const void* left, const void* right)
{
    long long leftValue = *((const long long*)left);
    long long rightValue = *((const long long*)right);

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
