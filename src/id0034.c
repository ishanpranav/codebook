// Licensed under the MIT License.

// Digit Factorials

#include "../lib/euler.h"
#include "../lib/exception.h"
#include "../lib/factorial.h"

int main(void)
{
    long sum = 0;
    clock_t start = clock();
    long long* factorials = factorial_range(10);

    euler_assert(factorials);

    long end = 7 * factorials[9];
    
    for (long n = 10; n <= end; n++)
    {
        long factorialSum = 0;

        for (long k = n; k; k /= 10)
        {
            factorialSum += factorials[k % 10];
        }

        if (n == factorialSum)
        {
            sum += n;
        }
    }

    free(factorials);

    return euler_submit(34, sum, start);
}
