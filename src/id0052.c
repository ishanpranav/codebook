// Licensed under the MIT License.

// Permuted Multiples

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/string_builder.h"

static bool math_is_permuted_multiple(
    long x,
    StringBuilder digits,
    StringBuilder image)
{
    for (int a = 2; a <= 6; a++)
    {
        string_builder_clear(digits);

        euler_ok(string_builder_append_format(digits, "%ld", a * x));

        if (!permutation_test(
            image->buffer,
            image->length,
            digits->buffer,
            digits->length,
            1,
            char_equality_comparer))
        {
            return false;
        }
    }

    return true;
}

static long math_permuted_multiple(StringBuilder digits, StringBuilder image)
{
    for (long x = 1; ; x++)
    {
        string_builder_clear(image);

        euler_ok(string_builder_append_format(image, "%ld", x));

        if (math_is_permuted_multiple(x, digits, image))
        {
            return x;
        }
    }

    return -1;
}

int main(void)
{
    struct StringBuilder image;
    struct StringBuilder digits;
    clock_t start = clock();
    
    euler_ok(string_builder(&digits, 0));
    euler_ok(string_builder(&image, 0));

    long result = math_permuted_multiple(&digits, &image);

    finalize_string_builder(&digits);
    finalize_string_builder(&image);

    return euler_submit(52, result, start);
}
