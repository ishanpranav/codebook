// Licensed under the MIT License.

// Sum Square Difference

#include "../lib/euler.h"

static long math_natural_sum_of_squares(long n)
{
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main(void)
{
    clock_t start = clock();
    long sum = math_natural_sum(100);
    long difference = sum * sum - math_natural_sum_of_squares(100);

    return euler_submit(6, difference, start);
}
