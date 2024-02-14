// Licensed under the MIT License.

// Roman to Integer

#include "../lib/roman.h"

int romanToInt(String value) 
{
    struct StringBuilder builder;

    string_builder_from_string(&builder, value);

    return roman_from_string_builder(&builder);
}
