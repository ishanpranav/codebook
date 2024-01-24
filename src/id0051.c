// Licensed under the MIT License.

// Prime Digit Replacements

#include "../lib/primality_tests/miller_rabin_primality_test.h"
#include "../lib/euler.h"
#include "../lib/sieve.h"

bool mask_list_mask(List value)
{
    int counts[10] = { 0 };

    for (long long* it = value->begin; it < value->end; it++)
    {
        counts[*it]++;
    }

    for (int i = 0; i <= 2; i++)
    {
        if (counts[i] < 2)
        {
            continue;
        }

        for (long long* it = value->begin; it < value->end; it++)
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

Exception math_prime_digit_replacement(
    Sieve primes,
    List mask,
    List image,
    long* first)
{
    struct SieveIterator it;

    for (sieve_begin(&it, primes); ; sieve_next(&it))
    {
        char str[7];

        sprintf(str, "%lld", *it.current);
        list_clear(mask);

        for (char* q = str; *q; q++)
        {
            Exception ex = list_add(mask, *q - '0');

            if (ex)
            {
                return ex;
            }
        }

        if (!mask_list_mask(mask))
        {
            continue;
        }

        long length = 0;

        *first = 0;

        for (int i = 0; i < 10; i++)
        {
            list_clear(image);

            for (long long* it = mask->begin; it < mask->end; it++)
            {
                Exception ex;

                if (*it == -1)
                {
                    ex = list_add(image, i);
                }
                else
                {
                    ex = list_add(image, *it);
                }

                if (ex)
                {
                    return ex;
                }
            }

            long n = 0;

            for (long long* q = image->begin; q < image->end; q++)
            {
                n = n * 10 + *q;
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

    ex = list(&mask, 0);

    euler_ok();

    struct List image;

    ex = list(&image, 0);

    long first;

    ex = math_prime_digit_replacement(&primes, &mask, &image, &first);

    euler_ok();

    finalize_sieve(&primes);
    finalize_list(&mask);
    finalize_list(&image);

    return euler_submit(51, first, start);
}
