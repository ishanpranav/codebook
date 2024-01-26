// Licensed under the MIT License.

// Odd Period Square Roots

#include "../lib/euler.h"

int main(void)
{
    int count = 0;
    clock_t start = clock();

    for (int s = 2; s < 10000; s++)
    {
        long isqrt;

        if (math_is_polygonal(4, s, &isqrt))
        {
            continue;
        }

        int a = isqrt;
        int h = 0;
        int i = 0;
        int k = 1;
        int end = 2 * a;

        while (a != end)
        {
            h = a * k - h;
            k = (s - h * h) / k;
            a = (isqrt + h) / k;
            i++;
        }

        count += i % 2;
    }

    return euler_submit(64, count, start);
}
