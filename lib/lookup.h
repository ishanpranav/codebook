// Licensed under the MIT License.

#include <stdbool.h>
#include "equality_comparer.h"
#include "exception.h"
#include "hash.h"
#include "lookup_entry.h"

/** Represents a collection of keys each mapped to one or more values. */
struct Lookup
{
    size_t (*keyHash)(void* item, size_t size);
    bool (*keyEqualityComparer)(void* left, void* right);

    struct LookupEntry** entries;
    size_t keySize;
    size_t valueSize;
    size_t count;
    size_t capacity;
    size_t maxCollisions;
    double minLoadFactor;
    bool exceedsMaxCollisions;
};

/** Represents a collection of keys each mapped to one or more values. */
typedef struct Lookup* Lookup;

/**
 * Initializes a new `Lookup` instance.
 * 
 * @param instance            the `Lookup` instance.
 * @param keySize             the size of each key in the multimap.
 * @param valueSize           the size of each value in the multimap.
 * @param capacity            the required minimum number of hash buckets.
 * @param keyEqualityComparer the comparer used to determine key equality.
 * @param keyHash             the hash function used to assign buckets.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception lookup(
    Lookup instance,
    size_t keySize,
    size_t valueSize,
    size_t capacity,
    EqualityComparer keyEqualityComparer,
    Hash keyHash);

/**
 * 
 * @param result
 * @param instance
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception lookup_from_lookup(Lookup result, Lookup instance);

/**
 * Adds the specified key-value pair to the multimap.
 * 
 * @param instance the `Lookup` instance.
 * @param key      the key to add to the multimap.
 * @param value    the value to add to the multimap.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception lookup_add(Lookup instance, Object key, Object value);

/**
 * Retrieves the number of matching values for the given key.
 * 
 * @param instance the `Lookup` instance.
 * @param key      the key.
 * @return The number of values with the given key.
*/
size_t lookup_count(Lookup instance, Object key);

/**
 * Adds the specified key-value pair to the multimap and retrieves the number
 * of matching values.
 * 
 * @param instance the `Lookup` instance.
 * @param key      the key to add to the multimap.
 * @param value    the value to add to the multimap.
 * @param matches  when this method returns, contains the total number of
 *                 elements with the given key, including the newly added value.
 *                 This argument is passed unitialized, or `NULL` if the value
 *                 will not be used.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception lookup_add_count(
    Lookup instance, 
    Object key, 
    Object value, 
    size_t* result);

/**
 * Removes all elements from the multimap.
 * 
 * @param instance the `Lookup` instance.
*/
void lookup_clear(Lookup instance);

/**
 * Frees all resources.
 *
 * @param instance the `Lookup` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_lookup(Lookup instance);
