// Licensed under the MIT License.

// Smallest Multiple

#include "../lib/euclidean.h"
#include "../lib/euler.h"

int main(void)
{
    long result = 2;
    clock_t start = clock();

    for (int i = 3; i <= 20; i++)
    {
        result = lcm(result, i);
    }

    return euler_submit(5, result, start);
}
