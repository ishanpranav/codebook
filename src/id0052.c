// Licensed under the MIT License.

// Permuted Multiples

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"

Exception math_is_permuted_multiple(
    long x,
    List digits,
    List image,
    bool* result)
{
    for (int a = 2; a <= 6; a++)
    {
        list_clear(digits);

        for (long k = a * x; k; k /= 10)
        {
            int d = k % 10;
            Exception ex = list_add(digits, &d);

            if (ex)
            {
                return ex;
            }
        }

        if (!permutation_test(image, digits, int_equality_comparer))
        {
            *result = false;

            return 0;
        }
    }

    *result = true;

    return 0;
}

Exception math_permuted_multiple(List digits, List image, long* result)
{
    for (long x = 1; ; x++)
    {
        list_clear(image);

        for (long k = x; k; k /= 10)
        {
            int d = k % 10;
            Exception ex = list_add(image, &d);

            if (ex)
            {
                return ex;
            }
        }

        bool is;
        Exception ex = math_is_permuted_multiple(x, digits, image, &is);

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
    struct List digits;
    clock_t start = clock();
    Exception ex = list(&digits, sizeof(int), 0);

    euler_ok();

    struct List image;
    
    ex = list(&image, sizeof(int), 0);

    euler_ok();

    long result;

    ex = math_permuted_multiple(&digits, &image, &result);

    euler_ok();

    finalize_list(&digits);
    finalize_list(&image);
    
    return euler_submit(52, result, start);
}
