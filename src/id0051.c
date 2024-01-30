// Licensed under the MIT License.

// Prime Digit Replacements

#include <stdlib.h>
#include "../lib/primality_tests/miller_rabin_primality_test.h"
#include "../lib/euler.h"
#include "../lib/lp_string_builder.h"
#include "../lib/sieve_iterator.h"

static bool mask_list_mask(LPStringBuilder value)
{
    int counts[10] = { 0 };

    for (size_t i = 0; i < value->length; i++)
    {
        counts[value->buffer[i] - '0']++;
    }

    for (int i = 0; i <= 2; i++)
    {
        if (counts[i] < 2)
        {
            continue;
        }

        for (size_t j = 0; j < value->length; j++)
        {
            if (value->buffer[j] - '0' == i)
            {
                value->buffer[j] = '*';
            }
        }

        return true;
    }

    return false;
}

static Exception math_prime_digit_replacement(
    Sieve primes,
    LPStringBuilder mask,
    LPStringBuilder image,
    long* first)
{
    Exception ex;
    struct SieveIterator it;

    for (sieve_begin(&it, primes); ; sieve_next(&it))
    {
        lp_string_builder_clear(mask);
        
        ex = lp_string_builder_append_format(mask, "%lld", *it.current);

        if (ex)
        {
            return ex;
        }

        if (!mask_list_mask(mask))
        {
            continue;
        }

        long length = 0;

        *first = 0;

        for (int i = 0; i < 10; i++)
        {
            lp_string_builder_clear(image);

            for (size_t j = 0; j < mask->length; j++)
            {
                if (mask->buffer[j] == '*')
                {
                    ex = lp_string_builder_append_char(image, i + '0');
                }
                else
                {
                    ex = lp_string_builder_append_char(image, mask->buffer[j]);
                }

                if (ex)
                {
                    return ex;
                }
            }

            long n = atol(image->buffer);
            
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

    struct LPStringBuilder mask;

    ex = lp_string_builder(&mask, 0);

    euler_ok();

    struct LPStringBuilder image;

    ex = lp_string_builder(&image, 0);

    long first;

    ex = math_prime_digit_replacement(&primes, &mask, &image, &first);

    euler_ok();

    finalize_sieve(&primes);
    finalize_lp_string_builder(&mask);
    finalize_lp_string_builder(&image);

    return euler_submit(51, first, start);
}
