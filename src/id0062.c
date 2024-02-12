// Licensed under the MIT License.

// Cubic Permutations

#include <limits.h>
#include "../lib/euler.h"
#include "../lib/comparer.h"
#include "../lib/string_builder.h"
#include "../lib/lookup_iterator.h"

static long long math_cubic_permutation(Lookup lookup)
{
    struct StringBuilder keyBuilder;

    euler_ok(string_builder(&keyBuilder, 0));

    for (long long b = 1; b < 10000; b++)
    {
        int count = 0;
        struct LookupIterator it;
        struct StringBuilder key;
        long long result = LLONG_MAX;
        long long cb = b * b * b;

        string_builder_clear(&keyBuilder);
        euler_ok(string_builder_append_format(&keyBuilder, "%lld", cb));
        string_builder_sort(&keyBuilder);
        qsort(keyBuilder.buffer, keyBuilder.length, 1, char_comparer);
        euler_ok(string_builder_copy(&key, &keyBuilder));
        euler_ok(lookup_add_begin(lookup, &key, &cb, &it));

        for (; !lookup_end(&it); lookup_next(&it))
        {
            count++;

            long long value = *(long long*)it.current->value;

            if (value < result)
            {
                result = value;
            }
        }

        if (count != 5)
        {
            continue;
        }

        finalize_string_builder(&keyBuilder);

        return result;
    }

    for (size_t i = 0; i < lookup->capacity; i++)
    {
        for (LookupEntry it = lookup->entries[i]; it; it = it->next)
        {
            printf("%s = %lld\n", ((StringBuilder)it->key)->buffer, (*(long long*)it->value));
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
