// Licensed under the MIT License.

// Pandigital Prime

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/prime_list.h"

int main(void)
{
    struct List digits;
    struct PrimeList primes;
    clock_t start = clock();
    Exception ex = list(&digits, 9);

    euler_ok();

    ex = prime_list(&primes, 10);

    for (int i = 1; i <= 3; i++)
    {
        list_add(&digits, i);
    }

    for (int i = 4; i <= 9; i++)
    {
        list_add(&digits, i);

        struct PermutationIterator it;

        for (permutation_begin(&it, &digits); !it.end; permutation_next(&it))
        {

        }
    }

    finalize_list(&digits);
    finalize_prime_list(&primes);
    euler_submit(41, product, start);
}
