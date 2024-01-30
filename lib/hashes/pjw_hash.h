// Licensed under the MIT License.

#include <stdint.h>
#include "../hash.h"

/**
 * Computes the PJW hash function used for Unix ELF files.
 * 
 * @param item the object.
 * @param size the size of the `item` argument.
 * @return A hash code for the given item.
*/
size_t pjw_hash(Object item, size_t size);

/**
 * Computes the PJW hash function used for Unix ELF files and returns a value
 * aligned to exactly 32 bits.
 * 
 * @param item the object.
 * @param size the size of the `item` argument.
 * @return A 32-bit hash code for the given item.
*/
uint32_t pjw_hash32(Object item, size_t size);
