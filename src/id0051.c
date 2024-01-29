// Licensed under the MIT License.

// Prime Digit Replacements

#include "../lib/primality_tests/miller_rabin_primality_test.h"
#include "../lib/euler.h"
#include "../lib/sieve_iterator.h"

static bool mask_list_mask(List value)
{
    int counts[10] = { 0 };
    int* begin = value->items;
    int* end = begin + value->count;

    for (int* it = begin; it < end; it++)
    {
        counts[*it]++;
    }

    for (int i = 0; i <= 2; i++)
    {
        if (counts[i] < 2)
        {
            continue;
        }

        for (int* it = begin; it < end; it++)
        {
            if (*it == i)
            {
                *it = -1;
            }
        }

        return true;
    }

    return false;
}

static Exception math_prime_digit_replacement(
    Sieve primes,
    List mask,
    List image,
    long* first)
{
    struct SieveIterator it;

    for (sieve_begin(&it, primes); ; sieve_next(&it))
    {
        list_clear(mask);

        for (long long k = *it.current; k; k /= 10)
        {
            int d = k % 10;
            Exception ex = list_add(mask, &d);

            if (ex)
            {
                return ex;
            }
        }

        list_reverse(mask);

        if (!mask_list_mask(mask))
        {
            continue;
        }

        long length = 0;

        *first = 0;

        for (int i = 0; i < 10; i++)
        {
            list_clear(image);

            int* begin = mask->items;
            int* end = begin + mask->count;

            for (int* it = begin; it < end; it++)
            {
                Exception ex;

                if (*it == -1)
                {
                    ex = list_add(image, &i);
                }
                else
                {
                    ex = list_add(image, it);
                }

                if (ex)
                {
                    return ex;
                }
            }

            long n = 0;

            begin = image->items;
            end = begin + image->count;

            for (int* it = begin; it < end; it++)
            {
                n = n * 10 + *it;
            }

            if (n <= 100000)
            {
                continue;
            }

            Primality test = sieve_test(primes, n, miller_rabin_primality_test);

            if (test != PRIMALITY_PRIME)
            {
                continue;
            }

            if (!length)
            {
                *first = n;
            }

            length++;
        }

        if (length == 8)
        {
            return 0;
        }
    }

    *first = -1;

    return 0;
}

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 0);

    euler_ok();

    struct List mask;

    ex = list(&mask, sizeof(int), 0);

    euler_ok();

    struct List image;

    ex = list(&image, sizeof(int), 0);

    long first;

    ex = math_prime_digit_replacement(&primes, &mask, &image, &first);

    euler_ok();

    finalize_sieve(&primes);
    finalize_list(&mask);
    finalize_list(&image);

    return euler_submit(51, first, start);
}
