// Licensed under the MIT License.

// Coded Triangle Numbers

#include <math.h>
#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/string_collection.h"

int main(void)
{
    struct List words;
    clock_t start = clock();
    Exception ex = list(&words, sizeof(String), 2000);

    euler_ok();

    ex = string_collection_deserialize(&words, stdin);

    euler_ok();

    int count = 0;
    String* begin = words.items;
    String* end = begin + words.count;

    for (String* word = begin; word < end; word++)
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
    
    return euler_submit(42, count, start);
}
