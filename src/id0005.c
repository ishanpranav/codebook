// Licensed under the MIT License.

// Smallest Multiple

#include "../lib/euclidean.h"
#include "../lib/euler.h"

static long math_lcm(long a, long b)
{
    return (a / gcd(a, b)) * b;
}

int main(void)
{
    long lcm = 2;
    clock_t start = clock();

    for (int i = 3; i <= 20; i++)
    {
        lcm = math_lcm(lcm, i);
    }

    return euler_submit(5, lcm, start);
}
