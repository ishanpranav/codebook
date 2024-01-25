// Licensed under the MIT License.

// Triangular, Pentagonal, and Hexagonal

#include "../lib/euler.h"

int main(void)
{
    long x = 0;
    clock_t start = clock();

    for (int n = 143 + 1; ; n++)
    {
        x = n * (2 * n - 1);

        if (math_is_polygonal(5, x, NULL))
        {
            break;
        }
    }

    return euler_submit(45, x, start);
}
