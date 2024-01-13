// Licensed under the MIT License.

// Digit Fifth Powers

#include <math.h>
#include "../lib/euler.h"

int main(void)
{
    long sum = 0;
    long limit = 6 * 9 * 9 * 9 * 9 * 9;
    clock_t start = clock();

    for (long i = 2; i <= limit; i++)
    {
        long sumPows = 0;

        for (long n = i; n; n /= 10)
        {
            sumPows += pow(n % 10, 5);
        }

        if (i == sumPows)
        {
            sum += i;
        }
    }

    return euler_submit(30, sum, start);
}
