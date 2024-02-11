// Licensed under the MIT License.

#include "lookup.h"

struct LookupIterator
{
    void* key;
    struct Lookup* instance;
    struct LookupEntry* current;
    size_t collisions;
};

typedef struct LookupIterator* LookupIterator;

/**
 * Adds the specified key-value pair to the multimap.
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
    
bool lookup_end(LookupIterator iterator);
void lookup_next(LookupIterator iterator);
