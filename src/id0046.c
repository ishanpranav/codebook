// Licensed under the MIT License.

// Goldbach's Other Conjecture

#include "../lib/primality_tests/miller_rabin_primality_test.h"
#include "../lib/euler.h"

bool math_is_goldbach_other_conjecture(long n)
{
    long m;

    for (long i = 0; (m = 2 * i * i) < n; i++)
    {
        if (miller_rabin_primality_test(n - m) == PRIMALITY_PRIME)
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    clock_t start = clock();

    long n;

    for (n = 9; ; n += 2)
    {
        if (miller_rabin_primality_test(n) == PRIMALITY_PRIME)
        {
            continue;
        }

        if (!math_is_goldbach_other_conjecture(n))
        {
            break;
        }
    }

    return euler_submit(46, n, start);
}
