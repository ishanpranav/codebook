// Licensed under the MIT License.

// Pandigital Prime

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/prime_list.h"

int main(void)
{
    struct List digits;
    clock_t start = clock();
    Exception ex = list(&digits, 9);

    euler_ok();
    
    struct PrimeList primes;

    ex = prime_list(&primes, 10);

    euler_ok();

    for (int i = 1; i <= 3; i++)
    {
        ex = list_add(&digits, i);

        euler_ok();
    }

    long max = 2143;

    for (int i = 4; i <= 9; i++)
    {
        ex = list_add(&digits, i);

        euler_ok();

        struct PermutationIterator it;

        for (permutation_begin(&it, &digits); !it.end; permutation_next(&it))
        {
            long n = 0;

            for (long* p = it.values->begin; p < it.values->end; p++)
            {
                n = n * 10 + *p;
            }

            if (n > max && prime_list_is_prime(&primes, n))
            {
                max = n;
            }
        }
    }

    finalize_list(&digits);
    finalize_prime_list(&primes);
    euler_submit(41, max, start);
}
