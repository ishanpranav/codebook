// Licensed under the MIT License.

#ifndef STRING_554c4c38a6694dd599b5d6e01dedb42d
#define STRING_554c4c38a6694dd599b5d6e01dedb42d
#include "object.h"
#include <stddef.h>

/** Represents text as a zero-terminated sequence of characters. */
typedef char* String;

/**
 * Initializes a new `String` instance with the given length.
 * 
 * @param length the string length.
 * @return A new string with the given length, or `NULL` if the process is out
 *         of memory. The caller is responsible.
*/
String string(size_t length);

/**
 * Creates a new instance of `String` with the same value as a specified
 * `String`.
 * 
 * @param instance the `String` instance to copy.
 * @return A new string with the same value, or `NULL` if the process is out of
 *         memory. The caller is responsible.
 */
String string_clone(String instance);

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
int string_comparer(const void* left, const void* right);

#endif
