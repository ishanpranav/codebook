// Licensed under the MIT License.

// Summation of Primes

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/euler_math.h"

int main(void)
{
    clock_t start = clock();
    long* primes = malloc(2000000l * sizeof * primes);
    long count = math_get_primes(2000000l, primes);

    if (!primes || count < 0)
    {
        euler_throw("Out of memory\n");
    }

    long long sum = 0;

    for (long i = 0; i < count; i++)
    {
        sum += primes[i];
    }

    euler_submit(10, sum, start);
    free(primes);

    return 0;
}
