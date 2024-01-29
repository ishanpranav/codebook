// Licensed under the MIT License.

// Names Scores

#include <stdlib.h>
#include <string.h>
#include "../lib/euler.h"
#include "../lib/lp_string_collection.h"

int main(void)
{
    long sum = 0;
    struct List names;
    clock_t start = clock();
    Exception ex = list(&names, sizeof(LPString), 5000);

    euler_ok();

    ex = lp_string_collection_deserialize(&names, stdin);

    euler_ok();

    list_sort(&names, lp_string_compare);

    LPString* begin = names.items;

    for (size_t i = 0; i < names.count; i++)
    {
        int rank = 0;

        for (char* p = begin[i]; *p; p++)
        {
            rank += *p - 'A' + 1;
        }

        sum += rank * (i + 1);

        free(begin[i]);
    }

    finalize_list(&names);

    return euler_submit(22, sum, start);
}
