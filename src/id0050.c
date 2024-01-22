// Licensed under the MIT License.

// Consecutive Prime Sum

#include "../lib/primality_tests/divisor_primality_test.h"
#include "../lib/euler.h"
#include "../lib/sieve.h"

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 1000000l);

    euler_ok();

    long maxSum = 0;
    long maxLength = 0;

    for (long* p = primes.primes.begin; p < primes.primes.end; p++)
    {
        long sum = 0;

        for (long* q = p; q < primes.primes.end; q++)
        {
            sum += *q;

            if (sum > 1000000l)
            {
                break;
            }

            if (sum <= maxSum)
            {
                continue;
            }

            long length = q - p;

            if (length <= maxLength)
            {
                continue;
            }

            Primality test = sieve_test(&primes, sum, divisor_primality_test);

            if (test != PRIMALITY_PRIME)
            {
                continue;
            }

            maxSum = sum;
            maxLength = length;
        }
    }

    return euler_submit(50, maxSum, start);
}
