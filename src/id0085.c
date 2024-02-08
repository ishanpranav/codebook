// Licensed under the MIT License.

// Counting Rectangles

#include <limits.h>
#include <math.h>
#include "../lib/euler.h"

int main(void)
{
    long maxWidth = 0;
    long maxHeight = 0;
    long minDelta = LONG_MAX;
    clock_t start = clock();
    int max = sqrt(2000000l);

    for (int width = 3; width <= max; width++)
    {
        for (int height = width + 1; height <= max; height++)
        {
            long count = math_natural_sum(width) * math_natural_sum(height);
            long delta = labs(count - 2000000l);

            if (delta < minDelta)
            {
                maxWidth = width;
                maxHeight = height;
                minDelta = delta;
            }
        }
    }

    long maxArea = maxWidth * maxHeight;

    return euler_submit(85, maxArea, start);
}
