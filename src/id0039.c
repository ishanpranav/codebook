// Licensed under the MIT License.

// Integer Right Triangles

#include "../lib/euler.h"
#include "../lib/pythagorean.h"

int main(void)
{
    int maxSum = 120;
    int maxTripletCount = 3;
    clock_t start = clock();
    int* counts = pythagorean_count_range(1001);

    euler_assert(counts);

    for (int sum = 0; sum < 1001; sum++)
    {
        if (counts[sum] > maxTripletCount)
        {
            maxSum = sum;
            maxTripletCount = counts[sum];
        }
    }

    free(counts);

    return euler_submit(39, maxSum, start);
}
