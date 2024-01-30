// Licensed under the MIT License.

#include "../hash.h"

/**
 * Computes the Daniel J. Bernstein (djb2) hash digest.
 * 
 * @param item the object.
 * @param size the size of the `item` argument.
 * @return A hash code for the given item.
*/
size_t djb2_hash(Object item, size_t size);
