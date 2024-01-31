// Licensed under the MIT License.

// Consecutive Prime Sum

#include "../lib/primality_tests/miller_rabin_primality_test.h"
#include "../lib/euler.h"
#include "../lib/sieve.h"

int main(void)
{
    long maxSum = 0;
    long maxLength = 0;
    struct Sieve primes;
    clock_t start = clock();

    euler_ok(sieve(&primes, 1000000l));

    long long* begin = primes.primes.items;
    long long* end = begin + primes.primes.count;

    for (long long* p = begin; p < end; p++)
    {
        long sum = 0;

        for (long long* q = p; q < end; q++)
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

            Primality test = sieve_test(
                &primes,
                sum,
                miller_rabin_primality_test);

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
