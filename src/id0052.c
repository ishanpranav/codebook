// Licensed under the MIT License.

// Permuted Multiples

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/lp_string_builder.h"

static Exception math_is_permuted_multiple(
    long x,
    LPStringBuilder digits,
    LPStringBuilder image,
    bool* result)
{
    for (int a = 2; a <= 6; a++)
    {
        lp_string_builder_clear(digits);

        Exception ex = lp_string_builder_append_format(digits, "%ld", a * x);

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
    LPStringBuilder digits, 
    LPStringBuilder image, 
    long* result)
{
    for (long x = 1; ; x++)
    {
        lp_string_builder_clear(image);

        Exception ex = lp_string_builder_append_format(image, "%ld", x);

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
    struct LPStringBuilder digits;
    clock_t start = clock();
    Exception ex = lp_string_builder(&digits, 0);

    euler_ok();

    struct LPStringBuilder image;

    ex = lp_string_builder(&image, 0);

    euler_ok();

    long result;

    ex = math_permuted_multiple(&digits, &image, &result);

    euler_ok();

    finalize_lp_string_builder(&digits);
    finalize_lp_string_builder(&image);

    return euler_submit(52, result, start);
}
