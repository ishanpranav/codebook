// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "binary_search.h"
#include "hash_set.h"

/** See https://planetmath.org/goodhashtableprimes. */
static size_t primes[] = 
{
    53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157l, 98317l,
    196613l, 393241l, 786433l, 1572869l, 3145739l, 6291469l, 12582917l,
    25165843l, 50331653l, 100663319l, 201326611l, 402653189l, 805306457l,
    1610612741l
};

Exception hash_set(
    HashSet instance,
    size_t itemSize,
    size_t capacity,
    EqualityComparer itemEqualityComparer,
    Hash itemHash)
{
    if (capacity < primes[0])
    {
        capacity = primes[0];
    }

    instance->entries = calloc(capacity, sizeof * instance->entries);

    if (!instance->entries)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->itemEqualityComparer = itemEqualityComparer;
    instance->itemHash = itemHash;
    instance->itemSize = itemSize;
    instance->count = 0;
    instance->capacity = capacity;
    instance->maxChainLength = 2;
    instance->minLoadFactor = 0;

    return 0;
}

Exception hash_set_from_hash_set(HashSet result, HashSet instance)
{   
    size_t capacity = instance->capacity * 2;
    size_t* prime = binary_search_first_after(
        &capacity, 
        primes, 
        26,
        sizeof * primes,
        size_comparer);

    if (prime && *prime > capacity)
    {
        capacity = *prime;
    }

    if (instance->count > capacity)
    {
        capacity = instance->count;
    }

    Exception ex = hash_set(
        result,
        instance->itemSize,
        capacity,
        instance->itemEqualityComparer,
        instance->itemHash);

    if (ex)
    {
        return ex;
    }

    for (size_t i = 0; i < instance->capacity; i++)
    {
        for (HashSetEntry it = instance->entries[i]; it; it = it->next)
        {
            ex = hash_set_add(result, it->item, NULL);

            if (ex)
            {
                finalize_hash_set(result);

                return ex;
            }
        }
    }

    return 0;
}

Exception hash_set_add(HashSet instance, Object item, bool* added)
{
    size_t hash = instance->itemHash(item, instance->itemSize);

    hash %= instance->capacity;

    size_t chainLength = 0;
    HashSetEntry* p;

    for (p = &instance->entries[hash]; *p; p = &(*p)->next)
    {
        chainLength++;

        if (!instance->itemEqualityComparer((*p)->item, item))
        {
            continue;
        }

        if (added)
        {
            *added = false;
        }

        return 0;
    }

    HashSetEntry entry = malloc(sizeof * entry);

    if (!entry)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    entry->item = malloc(instance->itemSize);

    if (!entry->item)
    {
        free(entry);

        return EXCEPTION_OUT_OF_MEMORY;
    }

    memcpy(entry->item, item, instance->itemSize);

    entry->next = NULL;
    *p = entry;
    instance->count++;

    if (added)
    {
        *added = true;
    }

    if (chainLength > instance->maxChainLength)
    {
        struct HashSet clone;

        if (hash_set_from_hash_set(&clone, instance) == 0)
        {
            finalize_hash_set(instance);
            memcpy(instance, &clone, sizeof clone);
        }
    }

    return 0;
}

bool hash_set_contains(HashSet instance, Object item)
{
    size_t hash = instance->itemHash(item, instance->itemSize);

    hash %= instance->capacity;

    for (HashSetEntry it = instance->entries[hash]; it; it = it->next)
    {
        if (instance->itemEqualityComparer(it->item, item))
        {
            return true;
        }
    }

    return false;
}

void hash_set_clear(HashSet instance)
{
    for (size_t i = 0; i < instance->capacity; i++)
    {
        HashSetEntry current = instance->entries[i];

        while (current)
        {
            HashSetEntry next = current->next;

            free(current->item);
            free(current);

            current = next;
        }

        instance->entries[i] = NULL;
    }

    instance->count = 0;
}

void finalize_hash_set(HashSet instance)
{
    hash_set_clear(instance);
    free(instance->entries);

    instance->itemHash = NULL;
    instance->itemEqualityComparer = NULL;
    instance->entries = NULL;
    instance->itemSize = 0;
    instance->capacity = 0;
}
