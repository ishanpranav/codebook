// Licensed under the MIT License.

// Triangular, Pentagonal, and Hexagonal

#include "../lib/euler.h"

int main(void)
{
    long n = 0;
    clock_t start = clock();

    for (int i = 143 + 1; ; i++)
    {
        n = i * (2 * i - 1);
        
        if (math_is_pentagonal(n))
        {
            break;
        }
    }

    return euler_submit(45, n, start);
}
