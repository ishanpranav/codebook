// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "hash_helpers.h"
#include "lookup.h"

Exception lookup(
    Lookup instance,
    size_t keySize,
    size_t valueSize,
    size_t capacity,
    EqualityComparer keyEqualityComparer,
    Hash keyHash)
{
    instance->capacity = hash_helpers_min_capacity(capacity);
    instance->entries = calloc(instance->capacity, sizeof * instance->entries);

    if (!instance->entries)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->keyEqualityComparer = keyEqualityComparer;
    instance->keyHash = keyHash;
    instance->keySize = keySize;
    instance->valueSize = valueSize;
    instance->count = 0;
    instance->maxCollisions = 2;
    instance->minLoadFactor = 0;
    instance->exceedsMaxCollisions = false;

    return 0;
}

static Exception lookup_add_impl(
    Lookup instance,
    Object key,
    Object value,
    size_t index)
{
    LookupEntry entry = malloc(sizeof * entry);

    if (!entry)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    entry->key = malloc(instance->keySize);

    if (!entry->key)
    {
        free(entry);

        return EXCEPTION_OUT_OF_MEMORY;
    }

    entry->value = malloc(instance->valueSize);

    if (!entry->value)
    {
        free(entry);
        free(entry->key);

        return EXCEPTION_OUT_OF_MEMORY;
    }

    memcpy(entry->key, key, instance->keySize);
    memcpy(entry->value, value, instance->valueSize);

    entry->next = instance->entries[index];
    instance->entries[index] = entry;
    instance->count++;

    return 0;
}

Exception lookup_from_lookup(Lookup result, Lookup instance)
{
    Exception ex = lookup(
        result,
        instance->keySize,
        instance->valueSize,
        hash_helpers_new_capacity(instance->count, instance->capacity),
        instance->keyEqualityComparer,
        instance->keyHash);

    if (ex)
    {
        return ex;
    }

    result->maxCollisions = instance->maxCollisions;
    result->minLoadFactor = instance->minLoadFactor;
    result->exceedsMaxCollisions = instance->exceedsMaxCollisions;

    for (size_t i = 0; i < instance->capacity; i++)
    {
        for (LookupEntry it = instance->entries[i]; it; it = it->next)
        {
            size_t hash = result->keyHash(it->key, instance->keySize);
            
            hash %= result->capacity;
            ex = lookup_add_impl(result, it->key, it->value, hash);

            if (ex)
            {
                finalize_lookup(result);

                return ex;
            }
        }
    }

    return 0;
}

static void lookup_rehash(Lookup instance)
{
    if (!instance->exceedsMaxCollisions)
    {
        return;
    }

    struct Lookup clone;

    if (lookup_from_lookup(&clone, instance) != 0)
    {
        return;
    }

    finalize_lookup(instance);
    memcpy(instance, &clone, sizeof clone);

    instance->exceedsMaxCollisions = false;
}

Exception lookup_add(Lookup instance, Object key, Object value)
{
    size_t hash = instance->keyHash(key, instance->keySize);
    
    hash %= instance->capacity;

    Exception ex = lookup_add_impl(instance, key, value, hash);

    if (ex)
    {
        return ex;
    }

    lookup_rehash(instance);

    return 0;
}

static size_t lookup_count_impl(Lookup instance, Object key, size_t index)
{
    size_t result = 0;
    size_t collisions = 0;

    for (LookupEntry it = instance->entries[index]; it; it = it->next)
    {
        if (instance->keyEqualityComparer(it->key, key))
        {
            result++;
        }
        else
        {
            collisions++;
        }
    }

    if (collisions > instance->maxCollisions)
    {
        instance->exceedsMaxCollisions = true;
    }

    return result;
}

size_t lookup_count(Lookup instance, Object key)
{
    size_t hash = instance->keyHash(key, instance->keySize);

    return lookup_count_impl(instance, key, hash % instance->capacity);
}

Exception lookup_add_count(
    Lookup instance,
    Object key,
    Object value,
    size_t* result)
{
    size_t hash = instance->keyHash(key, instance->keySize);

    hash %= instance->capacity;

    Exception ex = lookup_add_impl(instance, key, value, hash);

    if (ex)
    {
        return ex;
    }

    *result = lookup_count_impl(instance, key, hash);

    lookup_rehash(instance);
    
    return 0;
}

void lookup_clear(Lookup instance)
{
    for (size_t i = 0; i < instance->capacity; i++)
    {
        LookupEntry current = instance->entries[i];

        while (current)
        {
            LookupEntry next = current->next;

            free(current->key);
            free(current->value);
            free(current);

            current = next;
        }

        instance->entries[i] = NULL;
    }

    instance->count = 0;
}

void finalize_hash_set(Lookup instance)
{
    lookup_clear(instance);
    free(instance->entries);

    instance->keyHash = NULL;
    instance->keyEqualityComparer = NULL;
    instance->entries = NULL;
    instance->keySize = 0;
    instance->valueSize = 0;
    instance->capacity = 0;
    instance->maxCollisions = 0;
    instance->minLoadFactor = 0;
    instance->exceedsMaxCollisions = false;
}
