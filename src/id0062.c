// Licensed under the MIT License.

// Cubic Permutations

#include <limits.h>
#include "../lib/comparer.h"
#include "../lib/euler.h"
#include "../lib/string_builder.h"
#include "../lib/lookup_iterator.h"

static long long math_cubic_permutation(Lookup lookup)
{
    for (long long b = 1; b < 10000; b++)
    {
        int count = 0;
        struct LookupIterator it;
        struct StringBuilder key;
        long long result = LLONG_MAX;
        long long cb = b * b * b;

        euler_ok(string_builder(&key, 0));
        euler_ok(string_builder_append_format(&key, "%lld", cb));
        qsort(key.buffer, key.length, 1, char_comparer);
        euler_ok(lookup_add_begin(lookup, &key, &cb, &it));

        for (; !lookup_end(&it); lookup_next(&it))
        {
            long long value = *(long long*)it.current->value;

            if (value < result)
            {
                result = value;
            }

            count++;

            if (count == 5)
            {
                return result;
            }
        }
    }

    return -1;
}

int main(void)
{
    long long min = -1;
    struct Lookup l;
    clock_t start = clock();

    euler_ok(lookup(
        &l,
        sizeof(struct StringBuilder),
        sizeof(long long),
        0,
        string_builder_equals,
        string_builder_hash));

    l.maxCollisions = 11;
    min = math_cubic_permutation(&l);

    for (size_t i = 0; i < l.capacity; i++)
    {
        for (LookupEntry it = l.entries[i]; it; it = it->next)
        {
            finalize_string_builder(it->key);
        }
    }

    finalize_lookup(&l);

    return euler_submit(62, min, start);
}
