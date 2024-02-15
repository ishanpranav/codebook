// Licensed under the MIT License.

#include <string.h>
#include "square_digit_chain.h"

void square_digit_chain(SquareDigitChain instance)
{
    memset(instance->cache, 0, sizeof instance->cache);

    instance->cache[0] = 1;
    instance->cache[88] = 89;

    for (int n = 1; n < 568; n++)
    {
        instance->cache[n - 1] = square_digit_chain_get(instance, n);
    }
}

static int square_digits_chain_sum(long n, int results[])
{
    if (n < 568 && results[n - 1])
    {
        return results[n - 1];
    }

    long result = 0;

    for (long k = n; k; k /= 10)
    {
        int d = k % 10;

        result += d * d;
    }

    return result;
}

int square_digit_chain_get(SquareDigitChain instance, long n)
{
    while (n != 1 && n != 89)
    {
        n = square_digits_chain_sum(n, instance->cache);
    }

    return n;
}
