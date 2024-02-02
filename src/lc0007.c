// Licensed under the MIT License.

// Reverse Integer

#include <limits.h>
#include "../lib/euler.h"

int reverse(int value)
{
    long long result = math_reverse(value);

    if (result < INT_MIN || result > INT_MAX)
    {
        return 0;
    }

    return result;
}
