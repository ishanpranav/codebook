// Licensed under the MIT License.

// Multiples of 3 or 5

#include "../lib/euler.h"

long math_sum_multiples_3_5(long max)
{
    max--;

    return (3 * math_triangular(max / 3)) +
        (5 * math_triangular(max / 5)) -
        (15 * math_triangular(max / 15));
}

int main(void)
{
    clock_t start = clock();
    long sum = math_sum_multiples_3_5(1000);

    return euler_submit(1, sum, start);
}
