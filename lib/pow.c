// Licensed under the MIT License.

#include "pow.h"

long long mod_pow(long long b, long long a, long long mod)
{
    if (!mod)
    {
        mod = 1000000007l;
    }

    long long exponent = b;
    long long result = 1;

    while (a)
    {
        if (a % 2 == 1)
        {
            result = (result * exponent) % mod;
        }

        exponent = (exponent * exponent) % mod;
        a /= 2;
    }

    return result;
}
