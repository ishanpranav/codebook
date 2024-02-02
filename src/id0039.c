// Licensed under the MIT License.

// Integer Right Triangles

#include "../lib/euclidean.h"
#include "../lib/euler.h"

int main(void)
{
    int maxSum = 120;
    int maxTripletCount = 3;
    clock_t start = clock();
    int* tripletCounts = pythagorean_triplet_counts(1001);

    euler_assert(tripletCounts);

    for (int sum = 0; sum < 1001; sum++)
    {
        if (tripletCounts[sum] > maxTripletCount)
        {
            maxSum = sum;
            maxTripletCount = tripletCounts[sum];
        }
    }

    free(tripletCounts);

    return euler_submit(39, maxSum, start);
}
