// Licensed under the MIT License.

// Reciprocal Cycles

#include "../lib/euler.h"

static int math_reptend_length(int d)
{
    int n = 10;
    int order = 0;
    int result = 0;

    while (d % 5 == 0)
    {
        d /= 5;
    }

    while (d % 2 == 0)
    {
        d /= 2;
    }

    if (d == 1)
    {
        return 0;
    }

    while (!result)
    {
        order++;

        if (n % d == 1)
        {
            result = order;
        }
        else
        {
            n = (10 * n) % d;
        }
    }

    return result;
}

int main(void)
{
    int maxD = 0;
    int maxLength = 0;
    clock_t start = clock();

    for (int d = 2; d < 1000; d++)
    {
        int length = math_reptend_length(d);

        if (length > maxLength)
        {
            maxD = d;
            maxLength = length;
        }
    }

    return euler_submit(26, maxD, start);
}
