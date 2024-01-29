// Licensed under the MIT License.

// Integer Right Triangles

#include "../lib/euler.h"

static int math_pythagorean_triples(int sum)
{
    int result = 0;
    int end = sum / 2 - 1;

    for (int a = 3; a < end; a++)
    {
        int difference = sum - a;
        int c = (a * a + difference * difference) / (2 * difference);
        long b;

        if (math_is_polygonal(4, c * c - a * a, &b) && a + b + c == sum)
        {
            result++;
        }
    }

    return result;
}

int main(void)
{
    int maxSum = 120;
    int maxCount = 3;
    clock_t start = clock();

    for (int sum = maxSum; sum <= 1000; sum++)
    {
        int count = math_pythagorean_triples(sum);

        if (count > maxCount)
        {
            maxSum = sum;
            maxCount = count;
        }
    }

    return euler_submit(39, maxSum, start);
}
