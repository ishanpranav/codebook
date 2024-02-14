// Licensed under the MIT License.

// Integer to Roman

#include "../lib/roman.h"

String intToRoman(int value) 
{
    struct StringBuilder result;

    roman_to_string_builder(&result, value);

    return result.buffer;
}
