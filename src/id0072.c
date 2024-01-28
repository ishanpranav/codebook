// Licensed under the MIT License.

// Counting Fractions

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/exception.h"

long long math_summatory_totient(long max)
{
    long* phi = malloc(max * sizeof * phi);

    if (!phi)
    {
        return -1;
    }

    for (long m = 0; m < max; m++)
    {
        phi[m] = m;
    }

    for (long m = 2; m < max; m++)
    {
        if (phi[m] == m)
        {
            phi[m] = m - 1;

            for (long n = m + m; n < max; n += m)
            {
                phi[n] -= phi[n] / m;
            }
        }
    }

    long long result = 0;

    for (long m = 0; m < max; m++)
    {
        result += phi[m];
    }

    free(phi);

    return result;
}

int main(void)
{
    clock_t start = clock();
    long long result = math_summatory_totient(1000001);

    if (result == -1)
    {
        Exception ex = EXCEPTION_OUT_OF_MEMORY;

        euler_ok();
    }

    result--;

    return euler_submit(72, result, start);
}
