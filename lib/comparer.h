// Licensed under the MIT License.

#ifndef COMPARER_05e673bfc1d2477a8b652e51bb55e547
#define COMPARER_05e673bfc1d2477a8b652e51bb55e547
#include <stdbool.h>
#include "object.h"

/** Defines a method that a type implements to compare two objects. */
typedef int (*Comparer)(const void* left, const void* right);

int char_comparer(const void* left, const void* right);

/**
 * Compares this instance to a specified signed integer and returns an
 * indication of their relative values.
 * 
 * @param left  An integer to compare to `left`.
 * @param right An integer to compare to `right`.
 * @return A signed integer that indicates the relative values of `left` and 
 *         `right`.
*/
int int_comparer(const void* left, const void* right);

#endif 
