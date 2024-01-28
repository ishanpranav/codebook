// Licensed under the MIT License.

// Ordered Fractions

#include "../lib/euler.h"

int main(void)
{
    long minD = 1;
    long nStar = 0;
    long dStar = 1;
    clock_t start = clock();
    
    for (long d = 1000000l; d >= minD; d--)
    {
        long n = (3 * d - 1) / 7;

        if (nStar * d < n * dStar)
        {
            nStar = n;
            dStar = d;
            minD = d / (3 * d - 7 * n + 1);
        }
    }
    
    return euler_submit(71, nStar, start);
}
