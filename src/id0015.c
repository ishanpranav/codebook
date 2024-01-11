// Licensed under the MIT License.

// Lattice Paths

#include "../lib/euler.h"

long long math_binomial(int n, int k)
{
    if (k > n - k)
    {
        k = n - k;
    }

    long long result = 1;

    for (int i = 0; i < k; i++)
    {
        result *= n - i;
        result /= i + 1;
    }

    return result;
}

int main(void)
{
    clock_t start = clock();
    long long result = math_binomial(40, 20);

    euler_submit(15, result, start);
}
