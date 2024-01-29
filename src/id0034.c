// Licensed under the MIT License.

// Digit Factorials

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/exception.h"
#include "../lib/factorial.h"

int main(void)
{
    long sum = 0;
    clock_t start = clock();
    LPArray factorial = factorial_range(10);

    if (!factorial)
    {
        Exception ex = EXCEPTION_OUT_OF_MEMORY;

        euler_ok();
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

    free(factorial);

    return euler_submit(34, sum, start);
}
