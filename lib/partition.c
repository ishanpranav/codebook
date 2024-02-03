// Licensed under the MIT License.

#include <stdlib.h>

int* restricted_partition_range(int max, int constraints[], int length)
{
    if (max < 1)
    {
        return NULL;
    }

    int* result = calloc(max, sizeof * result);

    if (!result)
    {
        return NULL;
    }

    result[0] = 1;

    for (int i = 0; i < length; i++)
    {
        for (int j = constraints[i]; j < max; j++)
        {
            result[j] += result[j - constraints[i]];
        }
    }

    return result;
}
