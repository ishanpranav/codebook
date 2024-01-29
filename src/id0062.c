// Licensed under the MIT License.

// Cubic Permutations

#include <limits.h>
#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/list.h"
#include "../lib/lp_string_builder.h"
#define LOOKUP_BUCKETS 12289 // https://planetmath.org/goodhashtableprimes

struct LookupEntry
{
    struct LookupEntry* nextEntry;
    struct LPStringBuilder key;
    struct List values;
};

struct LookupBucket
{
    struct LookupEntry* firstEntry;
    struct LookupBucket* nextBucket;
};

struct Lookup
{
    struct LookupBucket* begin;
    struct LookupBucket* end;
    struct LookupBucket* firstBucket;
    size_t count;
    size_t bucketCount;
};

typedef struct LookupEntry* LookupEntry;
typedef struct LookupBucket* LookupBucket;
typedef struct Lookup* Lookup;

Exception lookup(Lookup instance, size_t buckets)
{
    instance->begin = malloc(buckets * sizeof * instance->begin);

    if (!instance->begin)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->end = instance->begin + buckets;

    for (LookupBucket it = instance->begin; it < instance->end; it++)
    {
        it->firstEntry = NULL;
        it->nextBucket = NULL;
    }

    return 0;
}

Exception lookup_add(
    Lookup instance,
    LPStringBuilder key,
    long long value,
    List* values)
{
    LookupEntry* p;
    size_t buckets = instance->end - instance->begin;
    size_t hash = lp_string_builder_get_hash_code(key) % buckets;

    for (p = &instance->begin[hash].firstEntry; *p; p = &(*p)->nextEntry)
    {
        if (lp_string_builder_equals(&(*p)->key, key))
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

    if (!instance->begin[hash].firstEntry)
    {
        LookupBucket first = instance->firstBucket;

        instance->begin[hash].nextBucket = first;
        instance->firstBucket = instance->begin + hash;
        instance->bucketCount++;
    }

    entry->key = *key;
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

            finalize_lp_string_builder(&current->key);
            finalize_list(&current->values);
            free(current);

            current = next;
        }

        it->firstEntry = NULL;
    }

    instance->count = 0;
    instance->bucketCount = 0;
    instance->firstBucket = NULL;
}

void finalize_lookup(Lookup instance)
{
    lookup_clear(instance);
    free(instance->begin);

    instance->begin = NULL;
    instance->end = NULL;
}

static int char_compare(const void* left, const void* right)
{
    return *((const char*)left) - *((const char*)right);
}

static Exception math_cubic_permutation(Lookup lookup, long long* result)
{
    for (long long max = 1; ;)
    {
        long long b = max;

        max *= 10;

        for (; b < max; b++)
        {
            long long cb = b * b * b;
            struct LPStringBuilder keyBuilder;
            Exception ex = lp_string_builder(&keyBuilder, 0);

            if (ex)
            {
                return ex;
            }

            lp_string_builder_clear(&keyBuilder);

            for (long long k = cb; k; k /= 10)
            {
                ex = lp_string_builder_append_char(&keyBuilder, '0' + k % 10);

                if (ex)
                {
                    return ex;
                }
            }

            qsort(
                keyBuilder.begin,
                keyBuilder.end - keyBuilder.begin,
                sizeof * keyBuilder.begin,
                char_compare);

            List matches;

            ex = lookup_add(lookup, &keyBuilder, cb, &matches);

            if (ex)
            {
                return ex;
            }

            if (matches->count != 5)
            {
                continue;
            }

            *result = LLONG_MAX;

            long long* begin = matches->items;
            long long* end = begin + matches->count;

            for (long long* it = begin; it < end; it++)
            {
                if (*it < *result)
                {
                    *result = *it;
                }
            }

            return 0;
        }
    }
}

int main(void)
{
    struct Lookup l;
    clock_t start = clock();
    Exception ex = lookup(&l, LOOKUP_BUCKETS);

    euler_ok();

    long long min = -1;

    ex = math_cubic_permutation(&l, &min);

    euler_ok();

    finalize_lookup(&l);

    return euler_submit(62, min, start);
}
