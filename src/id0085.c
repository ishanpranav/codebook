// Licensed under the MIT License.

// Counting Rectangles

#include <limits.h>
#include <math.h>
#include "../lib/euler.h"

int main(void)
{
    int maxWidth = 0;
    int maxHeight = 0;
    long long minDelta = LLONG_MAX;
    clock_t start = clock();
    int max = sqrt(2000000l);

    for (int width = 3; width <= max; width++)
    {
        for (int height = width + 1; height <= max; height++)
        {
            long long widthSum = math_natural_sum(width);
            long long heightSum = math_natural_sum(height);
            long long delta = llabs(widthSum * heightSum - 2000000l);

            if (delta < minDelta)
            {
                maxWidth = width;
                maxHeight = height;
                minDelta = delta;
            }
        }
    }

    int maxArea = maxWidth * maxHeight;

    return euler_submit(85, maxArea, start);
}
