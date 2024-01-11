// Licensed under the MIT License.

#include <stdio.h>
#include "euler.h"

int euler_submit(int id, long long result, clock_t start)
{
    printf(
        "%04d%64lld    %lf\n",
        id,
        result,
        (double)(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}

long math_natural_sum(long n)
{
    return n * (n + 1) / 2;
}
