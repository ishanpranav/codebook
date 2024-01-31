// Licensed under the MIT License.

// Cubic Permutations

#include <limits.h>
#include "../lib/euler.h"
#include "../lib/hash.h"
#include "../lib/list.h"
#include "../lib/string_builder.h"
#define LOOKUP_BUCKETS 12289 // https://planetmath.org/goodhashtableprimes

struct LookupEntry
{
    struct LookupEntry* nextEntry;
    struct StringBuilder key;
    struct List values;
};

struct LookupBucket
{
    struct LookupEntry* firstEntry;
    struct LookupBucket* nextBucket;
};

struct Lookup
{
    struct LookupBucket* buckets;
    struct LookupBucket* firstBucket;
    size_t count;
    size_t bucketCount;
    size_t usedBucketCount;
};

typedef struct LookupEntry* LookupEntry;
typedef struct LookupBucket* LookupBucket;
typedef struct Lookup* Lookup;

Exception lookup(Lookup instance, size_t bucketCount)
{
    instance->buckets = malloc(bucketCount * sizeof * instance->buckets);

    if (!instance->buckets)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->firstBucket = NULL;
    instance->count = 0;
    instance->bucketCount = bucketCount;
    instance->usedBucketCount = 0;

    for (size_t i = 0; i < bucketCount; i++)
    {
        instance->buckets[i].firstEntry = NULL;
        instance->buckets[i].nextBucket = NULL;
    }

    return 0;
}

Exception lookup_add(
    Lookup instance,
    StringBuilder key,
    long long value,
    List* values)
{
    LookupEntry* p;
    size_t hash = sdbm_hash(key->buffer, key->length) % instance->bucketCount;

    for (p = &instance->buckets[hash].firstEntry; *p; p = &(*p)->nextEntry)
    {
        if (string_builder_equals(&(*p)->key, key))
        {
            *values = &(*p)->values;

            return list_add(&(*p)->values, &value);
        }
    }

    LookupEntry entry = malloc(sizeof * entry);

    if (!entry)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    Exception ex = list(&entry->values, sizeof(long long), 1);

    if (ex)
    {
        free(entry);

        return ex;
    }

    list_add(&entry->values, &value);

    if (!instance->buckets[hash].firstEntry)
    {
        LookupBucket first = instance->firstBucket;

        instance->buckets[hash].nextBucket = first;
        instance->firstBucket = instance->buckets + hash;
        instance->usedBucketCount++;
    }

    string_builder_clone(&entry->key, key);

    entry->nextEntry = NULL;
    *p = entry;
    instance->count++;
    *values = &entry->values;

    return 0;
}

void lookup_clear(Lookup instance)
{
    for (LookupBucket it = instance->firstBucket; it; it = it->nextBucket)
    {
        LookupEntry current = it->firstEntry;

        while (current)
        {
            LookupEntry next = current->nextEntry;

            finalize_string_builder(&current->key);
            finalize_list(&current->values);
            free(current);

            current = next;
        }

        it->firstEntry = NULL;
    }

    instance->count = 0;
    instance->usedBucketCount = 0;
    instance->firstBucket = NULL;
}

void finalize_lookup(Lookup instance)
{
    lookup_clear(instance);
    free(instance->buckets);

    instance->buckets = NULL;
    instance->bucketCount = 0;
}

static long long math_cubic_permutation(Lookup lookup)
{
    struct StringBuilder keyBuilder;
    
    euler_ok(string_builder(&keyBuilder, 0));

    for (long long max = 1; ;)
    {
        long long b = max;

        max *= 10;

        for (; b < max; b++)
        {
            List matches;
            long long cb = b * b * b;

            string_builder_clear(&keyBuilder);
            euler_ok(string_builder_append_format(&keyBuilder, "%lld", cb));
            qsort(keyBuilder.buffer, keyBuilder.length, 1, char_comparer);
            euler_ok(lookup_add(lookup, &keyBuilder, cb, &matches));

            if (matches->count != 5)
            {
                continue;
            }

            long long result = LLONG_MAX;
            long long* begin = matches->items;
            long long* end = begin + matches->count;

            for (long long* it = begin; it < end; it++)
            {
                if (*it < result)
                {
                    result = *it;
                }
            }

            finalize_string_builder(&keyBuilder);

            return result;
        }
    }
}

int main(void)
{
    long long min = -1;
    struct Lookup l;
    clock_t start = clock();

    euler_ok(lookup(&l, LOOKUP_BUCKETS));
    
    min = math_cubic_permutation(&l);
    
    finalize_lookup(&l);

    return euler_submit(62, min, start);
}
