// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "hash_helpers.h"
#include "hash_set.h"

Exception hash_set(
    HashSet instance,
    size_t itemSize,
    size_t capacity,
    EqualityComparer itemEqualityComparer,
    Hash itemHash)
{
    instance->capacity = hash_helpers_min_capacity(capacity);
    instance->entries = calloc(instance->capacity, sizeof * instance->entries);

    if (!instance->entries)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->itemEqualityComparer = itemEqualityComparer;
    instance->itemHash = itemHash;
    instance->itemSize = itemSize;
    instance->count = 0;
    instance->maxChainLength = 2;
    instance->minLoadFactor = 0;

    return 0;
}

Exception hash_set_from_hash_set(HashSet result, HashSet instance)
{
    Exception ex = hash_set(
        result,
        instance->itemSize,
        hash_helpers_new_capacity(instance->count, instance->capacity),
        instance->itemEqualityComparer,
        instance->itemHash);

    if (ex)
    {
        return ex;
    }

    result->maxChainLength = SIZE_MAX;
    result->minLoadFactor = 0;

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

    result->maxChainLength = instance->maxChainLength;
    result->minLoadFactor = instance->minLoadFactor;
    
    return 0;
}

Exception hash_set_add(HashSet instance, Object item, bool* added)
{
    size_t hash = instance->itemHash(item, instance->itemSize);

    hash %= instance->capacity;

    size_t chainLength = 0;
    HashSetEntry* p;

    for (p = instance->entries + hash; *p; p = &(*p)->next)
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
    instance->maxChainLength = 0;
    instance->minLoadFactor = 0;
}
