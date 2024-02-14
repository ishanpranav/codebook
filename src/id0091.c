// Licensed under the MIT License.

// Right Triangles with Integer Coordinates

#include "../lib/euler.h"
#include "../lib/euclidean.h"

int main(void)
{
    int count = 0;
    clock_t start = clock();
    
    for (int x = 1; x <= 50; x++)
    {
        for (int y = 1; y <= 50; y++)
        {
            int d = gcd(x, y);
            int min = x * d / y;
            int other = (50 - y) * d / x;

            if (other < min)
            {
                min = other;
            }

            count += 2 * min;
        }
    }
    
    count += 50 * 50 * 3;

    return euler_submit(91, count, start);
}
