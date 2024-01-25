// Licensed under the MIT License.

// Odd Period Square Roots

#include "../lib/euler.h"

int main(void)
{
    int count = 0;
    clock_t start = clock();

    for (int n = 2; n < 10000; n++)
    {
        long isqrt = 0;

        if (math_is_polygonal(4, n, &isqrt))
        {
            continue;
        }

        int a = isqrt;
        int dn = 0;
        int k = 1;
        int i = 0;
        int end = 2 * a;

        while (a != end)
        {
            dn = a * k - dn;
            k = (n - dn * dn) / k;
            a = (isqrt + dn) / k;
            i++;
        }
    
        count += i % 2;
    }

    return euler_submit(64, count, start);
}
