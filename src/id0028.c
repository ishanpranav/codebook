// Licensed under the MIT License.

// Number Spiral Diagonals

#include "../lib/euler.h"

int main(void)
{
    int count = 1;
    long a0 = 1;
    long sum = a0;
    clock_t start = clock();

    while (count < 2 * 1001 - 1)
    {
        int increment = (count + 3) / 2;

        for (int i = 0; i < 4; i++)
        {
            a0 += increment;
            sum += a0;
        }

        count += 4;
    }

    return euler_submit(28, sum, start);
}
