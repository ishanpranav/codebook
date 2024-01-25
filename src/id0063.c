// Licensed under the MIT License.

// Powerful Digit Counts

#include <math.h>
#include "../lib/euler.h"

int main(void)
{
    int count = 0;
    clock_t start = clock();

    for (int n = 1; n < 22; n++)
    {
        for (int b = 1; b < 10; b++)
        {
            if (math_length(b, n) == n)
            {
                count++;
            }
        }
    }

    return euler_submit(63, count, start);
}
