// Licensed under the MIT License.

// Multiples of 3 or 5

#include "../lib/euler.h"

int main(void)
{
    clock_t start = clock();
    long sum = (3 * math_natural_sum(999 / 3)) +
        (5 * math_natural_sum(999 / 5)) -
        (15 * math_natural_sum(999 / 15));

    return euler_submit(1, sum, start);
}
