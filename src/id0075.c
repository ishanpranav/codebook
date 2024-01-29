// Licensed under the MIT License.

// Integer Right Triangles

#include "../lib/euler.h"

bool math_pythagorean_triples(long sum)
{
    long result = 0;
    long end = sum / 2 - 1;

    for (long a = 3; a < end; a++)
    {
        long difference = sum - a;
        long c = (a * a + difference * difference) / (2 * difference);
        long b;

        if (math_is_polygonal(4, c * c - a * a, &b) && a + b + c == sum)
        {
            result++;
        }

        if (result > 1)
        {
            return false;
        }
    }

    return result == 1;
}

int main(void)
{
    long count = 0;
    clock_t start = clock();

    return euler_submit(39, count, start);
}
