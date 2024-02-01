// Licensed under the MIT License.

// Names Scores

#include <string.h>
#include "../lib/euler.h"
#include "../lib/string_collection.h"
#include "../lib/sort.h"

struct LongString {
    char* value;
    // int extrabits;
};

int main(void)
{
    long sum = 0;
    struct List names;
    clock_t start = clock();
    
    euler_ok(list(&names, sizeof(struct LongString), 5000));
    euler_ok(string_collection_deserialize(&names, stdin));

    merge_sort(names.items, names.count, names.itemSize, string_comparer);
    //list_sort(&names, string_comparer);

    struct LongString* begin = names.items;

    for (size_t i = 0; i < names.count; i++)
    {
        int rank = 0;

        for (char* p = begin[i].value; *p; p++)
        {
            rank += *p - 'A' + 1;
        }

        sum += rank * (i + 1);

        free(begin[i].value);
    }

    finalize_list(&names);

    return euler_submit(22, sum, start);
}
