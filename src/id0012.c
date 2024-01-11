// Licensed under the MIT License.

// Highly Divisible Triangular Number

#include <math.h>
#include "../lib/euler.h"

int math_factors(long n)
{
    int result = 2;
    long max = sqrt(n);

    for (long d = 2; d <= max; d++)
    {
        if (n % d == 0)
        {
            result++;

            if (d != n / d)
            {
                result++;
            }
        }
    }

    return result;
}

int main(void)
{
    long i = 1;
    long n = 1;
    clock_t start = clock();

    while (math_factors(n) <= 500)
    {
        i++;
        n = n + i;
    }

    return euler_submit(12, n, start);
}
