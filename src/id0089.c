// Licensed under the MIT License.

// Roman Numerals

#include "../lib/euler.h"
#include "../lib/roman.h"
#include "../lib/words.h"

int main(void)
{
    char buffer[32];
    int difference = 0;
    clock_t start = clock();

    while (fgets(buffer, sizeof buffer, stdin))
    {
        struct StringBuilder builder;

        string_builder_from_string(&builder, buffer);
        string_builder_trim_right(&builder);

        int roman = roman_from_string_builder(&builder);

        difference += builder.length - roman_length(roman);
    }

    return euler_submit(89, difference, start);
}
