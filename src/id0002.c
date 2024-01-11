// Licensed under the MIT License.

// Even Fibonacci Numbers

#include "../lib/euler.h"

long math_even_fibonacci_sum(long n)
{
    if (n < 2)
    {
        return 0;
    }

    long ef1 = 0;
    long ef2 = 2;
    long sum = ef1 + ef2;

    while (ef2 <= n)
    {
        long ef3 = 4 * ef2 + ef1;

        if (ef3 > n)
        {
            break;
        }

        ef1 = ef2;
        ef2 = ef3;
        sum += ef2;
    }

    return sum;
}

int main(void)
{
    clock_t start = clock();
    long sum = math_even_fibonacci_sum(4000000l);

    return euler_submit(2, sum, start);
}
