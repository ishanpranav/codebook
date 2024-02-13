// Licensed under the MIT License.

#include <stdint.h>
#include "roman.h"
#define KEYS 13

static String romans[KEYS] =
{
    "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
};

static int values[KEYS] =
{
    1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
};

int roman_from_char(char value)
{
    switch (value)
    {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return 0;
    }
}

int roman_from_string_builder(StringBuilder value)
{
    if (value->length == 0)
    {
        return 0;
    }
    
    int result = 0;
    int previous = 0;
    int subtractive = false;

    for (size_t i = value->length - 1; i != SIZE_MAX; i--)
    {
        int current = roman_from_char(value->buffer[i]);

        subtractive = current < previous;
        previous = current;

        if (subtractive)
        {
            result -= current;
        }
        else
        {
            result += current;
        }
    }

    return result;
}

Exception roman_to_string_builder(StringBuilder result, int value)
{
    Exception ex = string_builder(result, 32);

    if (ex)
    {
        return ex;
    }

    for (int i = 0; i < KEYS; i++)
    {
        while (value / values[i])
        {
            ex = string_builder_append_string(result, romans[i]);

            if (ex)
            {
                return ex;
            }

            value -= values[i];
        }
    }

    return 0;
}
