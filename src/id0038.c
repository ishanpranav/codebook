// Licensed under the MIT License.

// Pandigital Multiples

#include "../lib/comparer.h"
#include "../lib/euler.h"
#include "../lib/string_builder.h"

int main(void)
{
    long max = 918273645l;
    struct StringBuilder digits;
    struct StringBuilder pandigital;
    clock_t start = clock();
    
    euler_ok(string_builder(&digits, 9));
    string_builder_from_string(&pandigital, "123456789");
    
    for (int i = 2; i < 10000; i++)
    {
        string_builder_clear(&digits);

        for (int j = 1; digits.length < 9; j++)
        {
            euler_ok(string_builder_append_format(&digits, "%ld", i * j));
        }

        long long n = atoll(digits.buffer);

        if (n <= max)
        {
            continue;
        }

        qsort(digits.buffer, digits.length, 1, char_comparer);

        if (!string_builder_equals(&digits, &pandigital))
        {
            continue;
        }

        max = n;
    }

    finalize_string_builder(&digits);

    return euler_submit(38, max, start);
}
