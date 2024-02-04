// Licensed under the MIT License.

#include <stdlib.h>

long long* partition_range(long max) 
{
    if (max < 1)
    {
        return NULL;
    }

    long long* result = calloc(max, sizeof * result);

    if (!result)
    {
        return NULL;
    }

    result[0] = 1;

    for (long i = 1; i < max; i++)
    {
        for (long j = i; j < max; j++)
        {
            result[j] += result[j - i];
        }
    }

    return result;
}

long long* mod_partition_range(long max, long long mod)
{
    if (max < 1)
    {
        return NULL;
    }

    long long* result = calloc(max, sizeof * result);

    if (!result)
    {
        return NULL;
    }

    if (!mod)
    {
        mod = 1000000007l;
    }

    result[0] = 1;
    
    for (long i = 1; i < max; i++)
    {
        long long current = 0;

        for (long j = 0; ; j++)
        {
            long k = j / 2 + 1;

            if (j % 2 == 1)
            {
                k = -k;
            }

            long pentagonal = k * (3 * k - 1) / 2;

            if (i < pentagonal)
            {
                break;
            }

            if (j % 4 < 2)
            {
                current += result[i - pentagonal];
            }
            else
            {
                current -= result[i - pentagonal];
            }

            current %= mod;
        }

        if (current < 0)
        {
            current = (current + mod) % mod;
        }

        result[i] = current;
    }

    return result;
}

long long* restricted_partition_range(long max, long long parts[], long length)
{
    if (max < 1)
    {
        return NULL;
    }

    long long* result = calloc(max, sizeof * result);

    if (!result)
    {
        return NULL;
    }

    result[0] = 1;

    for (long i = 0; i < length; i++)
    {
        for (long j = parts[i]; j < max; j++)
        {
            result[j] += result[j - parts[i]];
        }
    }

    return result;
}
