// Licensed under the MIT License.

#ifndef LP_STRING_554c4c38a6694dd599b5d6e01dedb42d
#define LP_STRING_554c4c38a6694dd599b5d6e01dedb42d
#include "object.h"
#include <stddef.h>

/** Represents text as a zero-terminated sequence of characters. */
typedef char* LPString;

/**
 * 
 * @param instance
 * @return A new string with the given length, or `NULL` if the process is out
 *         of memory.
*/
LPString lp_string(size_t length);

/**
 * Creates a new instance of `LPString` with the same value as a specified
 * `LPString`.
 * 
 * @param instance the `LPString` instance to copy.
 * @return A new string with the same value, or `NULL` if the process is out of
 *         memory. The caller is responsible.
 */
LPString lp_string_clone(LPString instance);

/**
 * Compares `left` with `right` and returns an integer that indicates whether
 * `left` precedes, follows, or appears in the same position in the sort order
 * as `right`.
 * 
 * @param left  a string to compare to `right`.
 * @param right a string to compare to `left`.
 * @return A signed integer that indicates the relative values of `left` and 
 *         `right`. 
*/
int lp_string_compare(const void* left, const void* right);

#endif
