// Licensed under the MIT License.

// Coded Triangle Numbers

#include <math.h>
#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/lp_string_collection.h"

int main(void)
{
    struct List words;
    clock_t start = clock();
    Exception ex = list(&words, sizeof(LPString), 2000);

    euler_ok();

    ex = lp_string_collection_deserialize(&words, stdin);

    euler_ok();

    int count = 0;
    LPString* begin = words.items;
    LPString* end = begin + words.count;

    for (LPString* word = begin; word < end; word++)
    {
        int x = 0;

        for (char* p = *word; *p; p++)
        {
            x += *p - 'A' + 1;
        }

        if (math_is_polygonal(3, x, NULL))
        {
            count++;
        }

        free(*word);
    }

    finalize_list(&words);
    euler_submit(42, count, start);
}
