// Licensed under the MIT License.

#include <stddef.h>
#include <stdint.h>
#include "object.h"

/** Defines a method that a type implements to hash an object. */
typedef size_t (*Hash)(Object item, size_t size);

/**
 * Computes the Daniel J. Bernstein (djb2) hash digest.
 * 
 * @param item the object.
 * @param size the size of the `item` argument.
 * @return A hash code for the given item.
*/
size_t djb2_hash(Object item, size_t size);

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

/**
 * Computes the SDBM hash digest.
 * 
 * @param item the object.
 * @param size the size of the `item` argument.
 * @return A hash code for the given item.
*/
size_t sdbm_hash(Object item, size_t size);
