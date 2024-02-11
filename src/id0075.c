// Licensed under the MIT License.

// Singular Integer Right Triangles

#include "../lib/euler.h"
#include "../lib/pythagorean.h"

int main(void)
{
    long count = 0;
    clock_t start = clock();
    int* counts = pythagorean_count_range(1500001l);

    euler_assert(counts);

    for (long sum = 0; sum < 1500001l; sum++)
    {
        if (counts[sum] == 1)
        {
            count++;
        }
    }

    free(counts);

    return euler_submit(75, count, start);
}
