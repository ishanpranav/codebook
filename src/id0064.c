// Licensed under the MIT License.

// Odd Period Square Roots

#include "../lib/euler.h"

int main(void)
{
    int count = 0;
    clock_t start = clock();

    for (int s = 2; s < 10000; s++)
    {
        long isqrt = 0;

        if (math_is_polygonal(4, s, &isqrt))
        {
            continue;
        }

        int a = 0;
        int r = 1;
        int i = 0;
        int a0 = isqrt;
        int end = 2 * a0;

        while (a0 != end)
        {
            a = a0 * r - a;
            r = (s - a * a) / r;
            a0 = (isqrt + a) / r;
            i++;
        }
    
        count += i % 2;
    }

    return euler_submit(64, count, start);
}
