// Licensed under the MIT License.

// Spiral Primes

#include "../lib/primality_tests/divisor_primality_test.h"
#include "../lib/euler.h"

int main(void)
{
    long count = 0;
    int length = 1;
    clock_t start = clock();

    do
    {
        length += 2;

        long loRight = length * length;
        long loLeft = loRight - length + 1;
        long hiLeft = loLeft - length + 1;
        long hiRight = hiLeft - length + 1;

        if (divisor_primality_test(loLeft) == PRIMALITY_PRIME)
        {
            count++;
        }

        if (divisor_primality_test(hiLeft) == PRIMALITY_PRIME)
        {
            count++;
        }

        if (divisor_primality_test(hiRight) == PRIMALITY_PRIME)
        {
            count++;
        }
    }
    while ((double)count / length >= 0.1 * 2);
    
    return euler_submit(58, length, start);
}
