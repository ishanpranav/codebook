// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "hash_helpers.h"
#include "lookup_iterator.h"

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
    instance->maxCollisions = SIZE_MAX;
    instance->minLoadFactor = 0;
    instance->overflow = false;

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

Exception lookup_copy(Lookup result, Lookup instance)
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
    result->overflow = instance->overflow;

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

static bool lookup_rehash(Lookup instance)
{
    if (!instance->overflow)
    {
        return false;
    }

    struct Lookup clone;

    if (lookup_copy(&clone, instance) != 0)
    {
        return false;
    }

    finalize_lookup(instance);
    memcpy(instance, &clone, sizeof clone);

    instance->overflow = false;

    return true;
}

Exception lookup_add(Lookup instance, Object key, Object value)
{
    size_t hash = instance->keyHash(key, instance->keySize);

    return lookup_add_impl(instance, key, value, hash % instance->capacity);
}

Exception lookup_add_begin(
    Lookup instance,
    Object key,
    Object value,
    LookupIterator iterator)
{
    size_t hash = instance->keyHash(key, instance->keySize);

    hash %= instance->capacity;

    Exception ex = lookup_add_impl(instance, key, value, hash);

    if (ex)
    {
        return ex;
    }

    if (lookup_rehash(instance))
    {
        hash = instance->keyHash(key, instance->keySize) % instance->capacity;
    }

    iterator->key = key;
    iterator->instance = instance;
    iterator->current = instance->entries[hash];
    iterator->collisions = 0;

    return 0;
}

bool lookup_end(LookupIterator iterator)
{
    if (!iterator->current)
    {
        if (iterator->collisions >= iterator->instance->maxCollisions)
        {
            iterator->instance->overflow = true;
        }

        return true;
    }

    return false;
}

void lookup_next(LookupIterator iterator)
{
    do
    {
        iterator->current = iterator->current->next;

        if (!iterator->current || iterator->instance->keyEqualityComparer(
            iterator->current->key,
            iterator->key))
        {
            return;
        }

        iterator->collisions++;
    }
    while (iterator->current);
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

void finalize_lookup(Lookup instance)
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
    instance->overflow = false;
}
