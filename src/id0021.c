// Licensed under the MIT License.

// Amicable Numbers

#include <math.h>
#include <stdlib.h>
#include "../lib/euler.h"

long math_proper_divisors(long n)
{
    long result = 1;
    long max = sqrt(n);

    for (long d = 2; d <= max; d++)
    {
        if (n % d == 0)
        {
            result += d;

            if (d != n / d)
            {
                result += n / d;
            }
        }
    }

    return result;
}

int main(void)
{
    long sum = 0;
    clock_t start = clock();
    int* sums = malloc(sizeof * sums * 9998);

    if (!sums)
    {
        euler_throw("Out of memory");
    }

    for (int a = 2; a < 10000; a++)
    {
        sums[a - 2] = math_proper_divisors(a);
    }

    for (int a = 2; a < 10000; a++)
    {
        int b = sums[a - 2];

        if (a != b && a == sums[b - 2])
        {
            sum += a;
        }
    }
    
    return euler_submit(21, sum, start);
}
