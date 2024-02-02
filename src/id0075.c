// Licensed under the MIT License.

// Singular Integer Right Triangles

#include "../lib/euclidean.h"
#include "../lib/euler.h"

int main(void)
{
    long count = 0;
    clock_t start = clock();
    int* tripletCounts = pythagorean_triplet_counts(1500001l);

    euler_assert(tripletCounts);

    for (long sum = 0; sum < 1500001l; sum++)
    {
        if (tripletCounts[sum] == 1)
        {
            count++;
        }
    }

    free(tripletCounts);

    return euler_submit(75, count, start);
}
