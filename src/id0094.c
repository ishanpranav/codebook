// Licensed under the MIT License.

// Right Triangles with Integer Coordinates

#include <math.h>
#include "../lib/euler.h"

int main(void)
{
    long x = 2;
    long y = 1;
    long sum = -2;
    clock_t start = clock();

    for (;;)
    {
        long long p = 2 * (3 * y - x) * (3 * y - x);

        if (p > 100000000)
        {
            break;
        }

        sum += p;
        p = 4 * x * x;
        
        if (p <= 100000000)
        {
            sum += p;
        }

        long nextX = x + x + 3 * y;
        long nextY = x + y + y;

        x = nextX;
        y = nextY;
    }

    return euler_submit(94, sum, start);
}
