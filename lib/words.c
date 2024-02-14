// Licensed under the MIT License.

#include <string.h>
#include "list.h"
#include "string_builder.h"
#include "words.h"

String words_to_string(int value)
{
    if (!value)
    {
        return "Zero";
    }

    static String ones[] =
    {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    static String tens[] =
    {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
        "Eighty", "Ninety"
    };
    static String groups[] =
    {
        "", "Thousand", "Million", "Billion"
    };
    struct List rope;
    int groupIndex = 0;

    Exception ex = list(&rope, sizeof(struct StringBuilder), 0);

    if (ex)
    {
        return NULL;
    }

    size_t length = 0;

    while (value)
    {
        if (value % 1000 != 0)
        {
            int part = value % 1000;
            struct StringBuilder group;

            ex = string_builder(&group, 0);

            if (ex)
            {
                return NULL;
            }

            if (part >= 100)
            {
                ex = string_builder_append_format(
                    &group,
                    " %s Hundred",
                    ones[part / 100]);

                if (ex)
                {
                    return NULL;
                }

                part %= 100;
            }

            if (part >= 20)
            {
                ex = string_builder_append_format(
                    &group,
                    " %s",
                    tens[part / 10]);

                if (ex)
                {
                    return NULL;
                }

                part %= 10;
            }

            if (part)
            {
                ex = string_builder_append_format(&group, " %s", ones[part]);

                if (ex)
                {
                    return NULL;
                }
            }

            ex = string_builder_append_format(
                &group,
                " %s",
                groups[groupIndex]);

            if (ex)
            {
                return NULL;
            }

            ex = list_add(&rope, &group);

            if (ex)
            {
                return NULL;
            }

            length += group.length;
        }

        value /= 1000;
        groupIndex++;
    }

    StringBuilder begin = rope.items;
    StringBuilder end = begin + rope.count;
    String result = string(length);
    char* current = result;

    if (!result)
    {
        return NULL;
    }

    for (StringBuilder it = end - 1; it >= begin; it--)
    {
        memcpy(current, it->buffer, it->length);

        current += it->length;

        finalize_string_builder(it);
    }

    if (current[-1] == ' ')
    {
        current--;
        length--;
    }

    *current = '\0';

    finalize_list(&rope);
    memmove(result, result + 1, length);

    return result;
}

int words_number_letter_counts(void)
{
    static int ones[] = { 3, 3, 5, 4, 4, 3, 5, 5, 4, 0 };
    static int teens[] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8, 0 };
    static int tens[] = { 6, 6, 5, 5, 5, 7, 6, 6, 0 };
    int sumOfOnes = 0;
    int sumOfTeens = 0;
    int sumOfTens = 0;
    
    for (int* it = ones; *it; it++)
    {
        sumOfOnes += *it;
    }   

    for (int* it = teens; *it; it++)
    {
        sumOfTeens += *it;
    }

    for (int* it = tens; *it; it++)
    {
        sumOfTens += *it;
    }

    return
        ones[0] + // one
        8 + // thousand
        sumOfOnes * 100 + // one, two, three, ...nine
        7 * 9 * 100 + // hundred
        3 * 9 * 99 + // and
        sumOfTens * 100 + // twenty, thirty, fourty, ...ninety
        sumOfTeens * 10 + // ten, eleven, twelve, ...nineteen
        sumOfOnes * 90; // one, two, three, ...nine
}
