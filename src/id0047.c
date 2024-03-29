// Licensed under the MIT License.

// Distinct Primes Factors

#include "../lib/euler.h"
#define MAX_SEARCH 1000000l

int main(void)
{
    clock_t start = clock();
    int* divisors = calloc(MAX_SEARCH, sizeof * divisors);

    euler_assert(divisors);

    long n;
    int length = 0;

    for (n = 2; n < MAX_SEARCH; n++)
    {
        if (divisors[n] == 4)
        {
            length++;

            if (length == 4)
            {
                break;
            }
        }
        else
        {
            length = 0;
        }

        if (divisors[n])
        {
            continue;
        }

        for (long j = n + n; j < MAX_SEARCH; j += n)
        {
            divisors[j]++;
        }
    }

    free(divisors);

    return euler_submit(47, n - 3, start);
}
