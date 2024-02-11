// Licensed under the MIT License.

#include "lookup.h"

/** Iterates over entries with matching keys in a multimap. */
struct LookupIterator
{
    void* key;
    struct Lookup* instance;
    struct LookupEntry* current;
    size_t collisions;
};

/** Iterates over entries with matching keys in a multimap. */
typedef struct LookupIterator* LookupIterator;

/**
 * Adds the specified key-value pair to the multimap and provides an iterator
 * over entries with matching keys.
 *
 * @param instance the `Lookup` instance.
 * @param key      the key to add to the multimap.
 * @param value    the value to add to the multimap.
 * @param iterator when this method returns, contains an iterator over all
 *                 matching entries with the given key. This argument is passed
 *                 uninitialized.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception lookup_add_begin(
    Lookup instance,
    Object key,
    Object value,
    LookupIterator iterator);

/**
 * Returns a value indicating whether the iterator can advance to the next
 * matching entry.
 *
 * @param iterator the iterator.
 * @return `true` if the iterator can successfully advance to the next matching
 *         entry; `false` if there are no more matching entries.
*/
bool lookup_end(LookupIterator iterator);

/**
 * Advances the iterator to the next matching entry.
 *
 * @param iterator the iterator.
*/
void lookup_next(LookupIterator iterator);
