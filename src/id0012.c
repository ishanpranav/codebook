// Licensed under the MIT License.

// Highly Divisible Triangular Number

#include <math.h>
#include "../lib/divisor_iterator.h"
#include "../lib/euler.h"

int math_divisors(long n)
{
    int result = 1;
    struct DivisorIterator it;

    for (divisor_begin(&it, n); !divisor_end(&it); divisor_next(&it))
    {
        result++;
    }

    return result;
}

int main(void)
{
    long i = 1;
    long n = 1;
    clock_t start = clock();

    while (math_divisors(n) <= 500)
    {
        i++;
        n = n + i;
    }

    return euler_submit(12, n, start);
}
