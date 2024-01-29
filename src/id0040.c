// Licensed under the MIT License.

// Champernowne's Constant

#include "../lib/euler.h"

static int champernowne_constant(long k)
{
    int n = 1;
    long long pow = 1;

    k--;

    for (;;)
    {
        long long block = pow * 9 * n;

        if (k < block)
        {
            break;
        }

        k -= block;
        pow *= 10;
        n++;
    }

    long long m = pow + k / n;

    for (long i = k % n; i < n - 1; i++)
    {
        m /= 10;
    }

    return m % 10;
}

int main(void)
{
    long product = 1;
    clock_t start = clock();

    for (long pow = 10; pow < 1000000l; pow *= 10)
    {
        product *= champernowne_constant(pow);
    }

    return euler_submit(40, product, start);
}
