// Licensed under the MIT License.

// Prime Permutations

#include "../lib/euler.h"
#include "../lib/string_builder.h"
#include "../lib/permutation_iterator.h"
#include "../lib/sieve.h"

static Exception math_prime_permutation(
    Sieve primes,
    StringBuilder aDigits,
    StringBuilder bDigits,
    StringBuilder cDigits,
    int min,
    int max,
    long long* result)
{
    for (int a = min; a < max; a++)
    {
        int b = a + 3330;
        int c = b + 3330;

        if (sieve_test(primes, a, NULL) != PRIMALITY_PRIME ||
            sieve_test(primes, b, NULL) != PRIMALITY_PRIME ||
            sieve_test(primes, c, NULL) != PRIMALITY_PRIME)
        {
            continue;
        }

        string_builder_clear(aDigits);

        Exception ex = string_builder_append_format(aDigits, "%d", a);

        if (ex)
        {
            return ex;
        }

        string_builder_clear(bDigits);

        ex = string_builder_append_format(bDigits, "%d", b);

        if (ex)
        {
            return ex;
        }

        if (!permutation_test(
            aDigits->buffer, 
            aDigits->length, 
            bDigits->buffer,
            bDigits->length,
            1,
            char_equality_comparer))
        {
            continue;
        }

        string_builder_clear(cDigits);

        ex = string_builder_append_format(cDigits, "%d", c);

        if (ex)
        {
            return ex;
        }

        if (!permutation_test(
            bDigits->buffer,
            bDigits->length,
            cDigits->buffer,
            cDigits->length,
            1,
            char_equality_comparer))
        {
            continue;
        }

        *result = a * 100000000ll + b * 10000 + c;
    }

    return 0;
}

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 10000);

    euler_ok();

    struct StringBuilder a;

    ex = string_builder(&a, 0);

    euler_ok();

    struct StringBuilder b;

    ex = string_builder(&b, 0);

    euler_ok();

    struct StringBuilder c;

    ex = string_builder(&c, 0);

    euler_ok();

    long long result = -1;

    ex = math_prime_permutation(&primes, &a, &b, &c, 2, 1487, &result);

    euler_ok();

    if (result < 0)
    {
        long long* begin = primes.primes.items;
        int last = begin[primes.primes.count - 1];

        ex = math_prime_permutation(&primes, &a, &b, &c, 1488, last, &result);

        euler_ok();
    }

    finalize_string_builder(&a);
    finalize_string_builder(&b);
    finalize_string_builder(&c);

    return euler_submit(49, result, start);
}
