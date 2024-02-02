// Licensed under the MIT License.

// String to Integer

#include <limits.h>
#include <stdlib.h>
#include "../lib/euler.h"

int myAtoi(String value) 
{
    long long result = atoll(value);

    if (result > INT_MAX)
    {
        return INT_MAX;
    }

    if (result < INT_MIN)
    {
        return INT_MIN;
    }

    return result;
}
