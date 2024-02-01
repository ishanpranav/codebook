// Licensed under the MIT License.

// Names Scores

#include <string.h>
#include "../lib/euler.h"
#include "../lib/string_collection.h"
#include "../lib/sort.h"

int main(void)
{
    long sum = 0;
    struct List names;
    clock_t start = clock();

    euler_ok(list(&names, sizeof(String), 5000));
    euler_ok(string_collection_deserialize(&names, stdin));

    qsort(names.items, names.count, names.itemSize, string_comparer);

    String* begin = names.items;

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
