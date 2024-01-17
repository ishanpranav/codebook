// Licensed under the MIT License.

// Pentagon Numbers

#include <limits.h>
#include <math.h>
#include "../lib/euler.h"

bool math_is_pentagonal(long n)
{
    double sqrtN = (sqrt(24 * n + 1) + 1) / 6;

    return sqrtN == (int)sqrtN;
}

int main(void)
{
    long min = LONG_MAX;
    clock_t start = clock();

    for (int m = 1; m < 10000; m++)
    {
        long j = (3 * m - 1) * m / 2;

        for (int n = m + 1; n < 10000; n++)
        {
            long k = (3 * n - 1) * n / 2;
            long d = k - j;

            if (d >= min)
            {
                continue;
            }

            if (!math_is_pentagonal(d) || !math_is_pentagonal(k + j))
            {
                continue;
            }

            min = k - j;
        }
    }

    return euler_submit(44, min, start);
}
