// Licensed under the MIT License.

#include <math.h>
#include <stdlib.h>
#include "binomial.h"

long long binomial(int n, int k)
{
    if (k > n - k)
    {
        k = n - k;
    }

    long long result = 1;

    for (int i = 0; i < k; i++)
    {
        result = (result * (n - i)) / (i + 1);
    }

    return result;
}

long long* binomial_mod_range(int max, long long mod)
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

    for (int i = 1; i < max; i++)
    {
        for (int j = max - 1; j > 0; j--)
        {
            result[j] = ((result[j] % mod) + (result[j - 1] % mod)) % mod;
        }
    }

    return result;
}
