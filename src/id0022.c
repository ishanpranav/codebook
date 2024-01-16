// Licensed under the MIT License.

// Names Scores

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/euler.h"
#include "../lib/lp_string_collection.h"

int main(void)
{
    // char buffer[65536];

    long sum = 0;
    int count = 0;
    struct LPStringCollection names;
    clock_t start = clock();
    Exception ex = lp_string_collection_deserialize(&names, stdin);

    // int read = fread(buffer, 1, sizeof buffer, stdin);

    // assert(read != 0);

    // LPString names[8192];

    euler_ok();

    // for (LPString tok = strtok(buffer, "\","); tok; tok = strtok(NULL, "\","))
    // {
    //     names[count] = lp_string_clone(tok);
    //     count++;
    // }

    lp_string_collection_sort(&names);

    // qsort(names, count, sizeof * names, lp_string_compare);

    for (int i = 0; i < count; i++)
    {
        int rank = 0;

        for (char* p = names.begin[i]; *p; p++)
        {
            rank += *p - 'A' + 1;
        }

        sum += rank * (i + 1);

        // free(names.begin[i]);
    }

    finalize_lp_string_collection(&names);

    return euler_submit(22, sum, start);
}
