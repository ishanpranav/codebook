// Licensed under the MIT License.

// Prime Digit Replacements

#include "../lib/primality_tests/miller_rabin_primality_test.h"
#include "../lib/euler.h"
#include "../lib/string_builder.h"
#include "../lib/sieve_iterator.h"

static bool mask_list_mask(StringBuilder value)
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

static long math_prime_digit_replacement(
    Sieve primes,
    StringBuilder mask,
    StringBuilder image)
{
    struct SieveIterator it;

    for (sieve_begin(&it, primes); ; sieve_next(&it))
    {
        string_builder_clear(mask);

        euler_ok(string_builder_append_format(mask, "%lld", it.current));

        if (!mask_list_mask(mask))
        {
            continue;
        }

        long result = 0;
        long length = 0;

        for (int i = 0; i < 10; i++)
        {
            string_builder_clear(image);

            for (size_t j = 0; j < mask->length; j++)
            {
                char c;

                if (mask->buffer[j] == '*')
                {
                    c = i + '0';
                }
                else
                {
                    c = mask->buffer[j];
                }

                euler_ok(string_builder_append_char(image, c));
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
                result = n;
            }

            length++;
        }

        if (length == 8)
        {
            return result;
        }
    }

    return -1;
}

int main(void)
{
    struct Sieve primes;
    struct StringBuilder mask;
    struct StringBuilder image;
    clock_t start = clock();

    euler_ok(sieve(&primes, 0));
    euler_ok(string_builder(&mask, 0));
    euler_ok(string_builder(&image, 0));

    long first = math_prime_digit_replacement(&primes, &mask, &image);

    finalize_sieve(&primes);
    finalize_string_builder(&mask);
    finalize_string_builder(&image);

    return euler_submit(51, first, start);
}
