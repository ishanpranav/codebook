// Licensed under the MIT License.

// Pentagon Numbers

#include <limits.h>
#include <math.h>
#include "../lib/euler.h"
#define MAX_SEARCH 10000

int main(void)
{
    long time = 0;
    long min = LONG_MAX;
    clock_t start = clock();

    for (int m = 1; m < MAX_SEARCH; m++)
    {
        long j = (3 * m - 1) * m / 2;

        for (int n = m + 1; n < MAX_SEARCH; n++)
        {
            time++;

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

            min = d;
        }
    }

    return euler_submit(44, min, start);
}
