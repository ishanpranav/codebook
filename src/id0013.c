// Licensed under the MIT License.

// Large Sum

#include "../lib/euler.h"

int main(void)
{
    long double x;
    long double result = 0;
    clock_t start = clock();

    while (scanf("%Lf\n", &x) == 1)
    {
        result += x;
    }

    while (result > 10000000000)
    {
        result /= 10;
    }

    return euler_submit(13, result, start);
}
