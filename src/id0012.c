// Licensed under the MIT License.

// Highly Divisible Triangular Number

#include <math.h>
#include "../lib/euler.h"
#include "../lib/sieve_iterator.h"

int math_divisors(Sieve primes, long n)
{
    int product = 1;
    struct SieveIterator it;

    for (sieve_begin(&it, primes); n != 1; sieve_next(&it)) 
    {
        int sum = 1;

        while (n % *it.current == 0)
        {
            sum++;
            n /= *it.current;
        }

        product *= sum;
    }

    return product;
}

int main(void)
{
    long i = 1;
    long n = 1;
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 0);

    euler_ok();

    while (math_divisors(&primes, n) <= 500)
    {
        i++;
        n = n + i;
    }

    return euler_submit(12, n, start);
}
