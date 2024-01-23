// Licensed under the MIT License.

// Coded Triangle Numbers

#include <math.h>
#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/lp_string_collection.h"

int main(void)
{
    struct LPStringCollection words;
    clock_t start = clock();
    Exception ex = lp_string_collection(&words, 5000);

    euler_ok();

    ex = lp_string_collection_deserialize(&words, stdin);

    euler_ok();

    int count = 0;

    for (LPString* word = words.begin; word < words.end; word++)
    {
        int x = 0;

        for (char* p = *word; *p; p++)
        {
            x += *p - 'A' + 1;
        }

        if (math_is_polygonal(3, x))
        {
            count++;
        }

        free(*word);
    }

    finalize_lp_string_collection(&words);
    euler_submit(42, count, start);
}
