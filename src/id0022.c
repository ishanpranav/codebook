// Licensed under the MIT License.

// Names Scores

#include "../lib/euler.h"
#include "../lib/lp_string_collection.h"

int main(void)
{
    long sum = 0;
    struct LPStringCollection names;
    clock_t start = clock();
    Exception ex = lp_string_collection(&names, 5000);

    euler_ok();

    ex = lp_string_collection_deserialize(&names, stdin);

    euler_ok();

    lp_string_collection_sort(&names);

    size_t count = names.end - names.begin;

    for (size_t i = 0; i < count; i++)
    {
        int rank = 0;

        for (char* p = names.begin[i]; *p; p++)
        {
            rank += *p - 'A' + 1;
        }

        sum += rank * (i + 1);
    }

    finalize_lp_string_collection(&names);

    return euler_submit(22, sum, start);
}
