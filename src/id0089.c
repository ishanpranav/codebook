// Licensed under the MIT License.

// Roman Numerals

#include "../lib/euler.h"
#include "../lib/roman.h"

int main(void)
{
    long sum = 0;
    clock_t start = clock();
    struct StringBuilder result;

    roman_to_string_builder(&result, 16);
    printf("%s\n", result.buffer);
    finalize_string_builder(&result);
    string_builder_from_string(&result, "XVI");
    printf("%d\n", roman_from_string_builder(&result));

    return euler_submit(89, sum, start);
}
