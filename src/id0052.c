// Licensed under the MIT License.

// Permuted Multiples

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/string_builder.h"

static Exception math_is_permuted_multiple(
    long x,
    StringBuilder digits,
    StringBuilder image,
    bool* result)
{
    for (int a = 2; a <= 6; a++)
    {
        string_builder_clear(digits);

        Exception ex = string_builder_append_format(digits, "%ld", a * x);

        if (ex)
        {
            return ex;
        }

        if (!permutation_test(
            image->buffer,
            image->length,
            digits->buffer,
            digits->length,
            1,
            char_equality_comparer))
        {
            *result = false;

            return 0;
        }
    }

    *result = true;

    return 0;
}

static Exception math_permuted_multiple(
    StringBuilder digits, 
    StringBuilder image, 
    long* result)
{
    for (long x = 1; ; x++)
    {
        string_builder_clear(image);

        Exception ex = string_builder_append_format(image, "%ld", x);

        if (ex)
        {
            return ex;
        }

        bool is;
        ex = math_is_permuted_multiple(x, digits, image, &is);

        if (ex)
        {
            return ex;
        }

        if (is)
        {
            *result = x;

            return 0;
        }
    }

    *result = -1;

    return 0;
}

int main(void)
{
    struct StringBuilder digits;
    clock_t start = clock();
    Exception ex = string_builder(&digits, 0);

    euler_ok();

    struct StringBuilder image;

    ex = string_builder(&image, 0);

    euler_ok();

    long result;

    ex = math_permuted_multiple(&digits, &image, &result);

    euler_ok();

    finalize_string_builder(&digits);
    finalize_string_builder(&image);

    return euler_submit(52, result, start);
}
