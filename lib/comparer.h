// Licensed under the MIT License.

#ifndef COMPARER_05e673bfc1d2477a8b652e51bb55e547
#define COMPARER_05e673bfc1d2477a8b652e51bb55e547
#include <stdbool.h>

/** Defines a method that a type implements to compare two objects. */
typedef int (*Comparer)(const void* left, const void* right);

/**
 * Compares this instance to a specified character and returns an indication of
 * their relative values.
 * 
 * @param left  A character to compare to `left`.
 * @param right A character to compare to `right`.
 * @return A signed integer that indicates the relative values of `left` and 
 *         `right`.
*/
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

/**
 * Compares this instance to a specified signed integer and returns an
 * indication of their relative values. This method performs the reverse
 * lexicographical comparison.
 * 
 * @param left  An integer to compare to `left`.
 * @param right An integer to compare to `right`.
 * @return A signed integer that indicates the relative values of `left` and 
 *         `right` in reverse-lexicographical order.
*/
int reverse_int_comparer(const void* left, const void* right);

/**
 * Compares this instance to a specified signed integer and returns an
 * indication of their relative values.
 * 
 * @param left  An integer to compare to `left`.
 * @param right An integer to compare to `right`.
 * @return A signed integer that indicates the relative values of `left` and 
 *         `right`.
*/
int long_long_comparer(const void* left, const void* right);

#endif 
