// Licensed under the MIT License.

#include <stdbool.h>
#include "equality_comparer.h"
#include "exception.h"
#include "hash.h"
#include "hash_set_entry.h"

/** Represents a set of values. */
struct HashSet
{
    size_t (*itemHash)(void* item, size_t size);
    bool (*itemEqualityComparer)(void* left, void* right);

    struct HashSetEntry** entries;
    size_t itemSize;
    size_t count;
    size_t capacity;
    size_t maxChainLength;
    double minLoadFactor;
};

/** Represents a set of values. */
typedef struct HashSet* HashSet;

/**
 * Initializes a new `HashSet` instance.
 * 
 * @param instance             the `HashSet` instance.
 * @param itemSize             the size of each element in the set.
 * @param capacity             the required minimum number of hash buckets.
 * @param itemEqualityComparer the comparer used to determine item equality.
 * @param itemHash             the hash function used to assign buckets.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception hash_set(
    HashSet instance,
    size_t itemSize,
    size_t capacity,
    EqualityComparer itemEqualityComparer,
    Hash itemHash);

/**
 * 
 * @param result
 * @param instance
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception hash_set_from_hash_set(HashSet result, HashSet instance);

/**
 * Adds the specified element to the set.
 * 
 * @param instance the `HashSet` instance.
 * @param item     the element to add to the set.
 * @param added    when this method returns, contains `true` if the element is
 *                 added to the set; `false` if the element is already present.
 *                 This argument is passed unitialized, or `NULL` if the value
 *                 will not be used.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception hash_set_add(HashSet instance, Object item, bool* added);

/**
 * Determines whether the set contains the specified element.
 * 
 * @param instance the `HashSet` instance.
 * @param item     the element to locate in the set.
 * @return `true` if the set contains the specified element; otherwise, `false`.
*/
bool hash_set_contains(HashSet instance, Object item);

/**
 * Removes all elements from the set.
 * 
 * @param instance the `HashSet` instance.
*/
void hash_set_clear(HashSet instance);

/**
 * Frees all resources.
 *
 * @param instance the `HashSet` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_hash_set(HashSet instance);
