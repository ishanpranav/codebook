// Licensed under the MIT License.

#include <stdbool.h>
#include "object.h"

/** Defines methods to support the comparison of objects for equality. */
typedef bool (*EqualityComparer)(Object left, Object right);

/**
 * Returns a value indicating whether `left` is equal to `right`.
 * 
 * @param left  a signed integer to compare to `left`.
 * @param right a signed integer to compare to `right`.
 * @param return `true` if `left` has the same value as `right`; otherwise,
 *               `false.`
*/
bool int_equality_comparer(Object left, Object right);

/**
 * Returns a value indicating whether `left` is equal to `right`.
 * 
 * @param left  a signed integer to compare to `left`.
 * @param right a signed integer to compare to `right`.
 * @param return `true` if `left` has the same value as `right`; otherwise,
 *               `false.`
*/
bool long_equality_comparer(Object left, Object right);

/**
 * Returns a value indicating whether `left` is equal to `right`.
 * 
 * @param left  a double-precision floating-point value to compare to `left`.
 * @param right a double-precision floating-point value to compare to `right`.
 * @param return `true` if `left` has the same value as `right`; otherwise,
 *               `false.`
*/
bool double_equality_comparer(Object left, Object right);
