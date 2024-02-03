// Licensed under the MIT License.

#include <stdlib.h>
#include "factorial.h"

long long* factorial_range(int max)
{
    if (max < 1)
    {
        return NULL;
    }

    long long* result = malloc(max * sizeof * result);

    if (!result)
    {
        return NULL;
    }

    result[0] = 1;

    for (int i = 1; i < max; i++)
    {
        result[i] = i * result[i - 1];
    }

    return result;
}
