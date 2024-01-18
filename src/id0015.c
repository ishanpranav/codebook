// Licensed under the MIT License.

// Lattice Paths

#include "../lib/euler.h"

int main(void)
{
    clock_t start = clock();
    long long result = math_binomial(40, 20);

    return euler_submit(15, result, start);
}
