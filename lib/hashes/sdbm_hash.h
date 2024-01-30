// Licensed under the MIT License.

#include "../hash.h"

/**
 * Computes the SDBM hash digest.
 * 
 * @param item the object.
 * @param size the size of the `item` argument.
 * @return A hash code for the given item.
*/
size_t sdbm_hash(Object item, size_t size);
