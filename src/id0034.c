// Licensed under the MIT License.

// Digit Factorials

#include "../lib/euler.h"

int main(void)
{
    long sum = 0;
    long factorial[10] = { [0] = 1 };
    clock_t start = clock();

    for (int i = 1; i <= 9; i++)
    {
        factorial[i] = i * factorial[i - 1];
    }
    
    long end = 7 * factorial[9];
    
    for (long n = 10; n <= end; n++)
    {
        long factorialSum = 0;

        for (long k = n; k; k /= 10)
        {
            factorialSum += factorial[k % 10];
        }

        if (n == factorialSum)
        {
            sum += n;
        }
    }

    return euler_submit(34, sum, start);
}
