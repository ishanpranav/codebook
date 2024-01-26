// Licensed under the MIT License.

// Longest Collatz Sequence

#include "../lib/euler.h"

int main(void)
{
    int result = 0;
    int maxLength = 10;
    clock_t start = clock();

    for (long i = 13; i < 1000000l; i++)
    {
        int length = 0;
        long n = i;

        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = 3 * n + 1;
            }

            length++;
        }

        if (length > maxLength)
        {
            maxLength = length;
            result = i;
        }
    }

    return euler_submit(14, result, start);
}
