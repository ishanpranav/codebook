// Licensed under the MIT License.

// Lattice Paths

#include "../lib/binomial.h"
#include "../lib/euler.h"

int main(void)
{
    clock_t start = clock();
    long long result = binomial(40, 20);

    return euler_submit(15, result, start);
}
