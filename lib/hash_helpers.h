// Licensed under the MIT License.

#include <stddef.h>

/**
 * Determines the recommended capacity for a hash table given its required
 * minimum capacity. This method should only be used when determining the
 * initial table size for an empty collection.
 * 
 * @param capacity the required minimum capacity.
 * @return The recommended capacity.
*/
size_t hash_helpers_min_capacity(size_t capacity);

/**
 * Determines the recommended capacity for a growing hash table given its
 * current entry count and capacity. This method should only be used when
 * scaling an existing table by a constant factor.
 * 
 * @param count    the current number of entries.
 * @param capacity the current capacity.
 * @return The recommended reallocation capacity.
*/
size_t hash_helpers_new_capacity(size_t count, size_t capacity);
