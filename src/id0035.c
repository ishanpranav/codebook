// Licensed under the MIT License.

// Circular Primes

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/prime_list.h"

bool math_is_circular_prime(long n, PrimeList primes, List digits)
{
    list_clear(digits);

    for (long k = n; k; k /= 10)
    {
        list_add(digits, k % 10);
    }

    struct PermutationIterator it;

    for (permutation_begin(&it, digits); !it.end; permutation_next(&it))
    {
        long k = 0;

        for (long* q = it.values->begin; q < it.values->end; q++)
        {
            k = k * 10 + *q;
        }

        if (!prime_list_is_prime(primes, k))
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    long values[6];
    struct List digits;
    struct PrimeList primes;
    clock_t start = clock();
    Exception ex = prime_list(&primes, 1000000l);

    euler_ok();
    list_from_array(&digits, values, 6);

    int count = 0;

    for (long* p = primes.primes.begin; p < primes.primes.end; p++)
    {
        if (math_is_circular_prime(*p, &primes, &digits))
        {
            count++;
        }
    }

    finalize_prime_list(&primes);

    return euler_submit(35, count, start);
}
