// Licensed under the MIT License.

// Smallest Multiple

#include "lib/euler.h"

long math_gcd(long a, long b)
{
    while (b > 0)
    {
        long r = a % b;

        a = b;
        b = r;
    }

    return a;
}

long math_lcm(long a, long b)
{
    return (a / math_gcd(a, b)) * b;
}

int main(void)
{
    long lcm = 2;
    clock_t start = clock();

    for (int i = 3; i <= 20; i++)
    {
        lcm = math_lcm(lcm, i);
    }

    euler_submit(5, lcm, start);

    return 0;
}
