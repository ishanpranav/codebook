// Licensed under the MIT License.

#ifndef LIST_95a94c0379b44bd3967523c81d4caa55
#define LIST_95a94c0379b44bd3967523c81d4caa55
#include <stdbool.h>
#include <stddef.h>
#include "exception.h"

/** Represents a list of integers that can be accessed by index. */
struct List
{
    long long* begin;
    long long* end;
    size_t capacity;
};

/** Represents a list of integers that can be accessed by index. */
typedef struct List* List;

/**
 * Initializes a `List` instance.
 *
 * @param instance the `List` instance.
 * @param capacity the required minimum capacity.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception list(List instance, size_t capacity);

/**
 * Intializes a `List` instance. Do not call `finalize_list`.
 *
 * @param instance the `List` instance.
 * @param values   the backing array for the list. The caller is responsible for
 *                 this argument.
 * @param length   the length of the `values` argument.
*/
void list_from_array(List instance, long long values[], size_t length);

/**
 * Adds an item to the end of the list.
 *
 * @param instance the `List` instance.
 * @param item     the item to add.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception list_add(List instance, long long item);

/**
 * Determines whether an element is in the list.
 *
 * @param instance the `List` instance.
 * @param item     the item to locate in the list.
 * @return `true` if the `item` is found in the list; otherwise, `false`.
*/
bool list_contains(List instance, long long item);

/**
 * Removes all elements from the list.
 * 
 * @param instance the `List` instance.
*/
void list_clear(List instance);

/**
 * Sorts the elements in the list.
 * 
 * @param instance the `List` instance.
*/
void list_sort(List instance);

/**
 * Reverses the order of the elements in the list.
 * 
 * @param instance the `List` instance.
*/
void list_reverse(List instance);

/**
 * Determines whether two lists are equal.
 * 
 * @param left  a list to compare to `right`. 
 * @param right a list to compare to `left`.
 * @return `true` if the two lists are of equal length and their corresponding
 *         elements are equal; otherwise, `false`.
*/
bool list_equals(List left, List right);

/**
 * Computes the summation of the terms in the list.
 * 
 * @param instance the `List` instance.
 * @return the summation of `instance`.
*/
long long list_sum(List instance);

/**
 * Frees all resources.
 *
 * @param instance the `List` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_list(List instance);

#endif
