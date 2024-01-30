// Licensed under the MIT License.

#ifndef LIST_95a94c0379b44bd3967523c81d4caa55
#define LIST_95a94c0379b44bd3967523c81d4caa55
#include <stdbool.h>
#include <stddef.h>
#include "comparer.h"
#include "equality_comparer.h"
#include "exception.h"

/** Represents a list of objects that can be accessed by index. */
struct List
{
    void* items;
    size_t itemSize;
    size_t count;
    size_t capacity;
};

/** Represents a list of objects that can be accessed by index. */
typedef struct List* List;

/**
 * Initializes a `List` instance.
 *
 * @param instance the `List` instance.
 * @param itemSize the size of each element in the list.
 * @param capacity the required minimum capacity.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception list(List instance, size_t itemSize, size_t capacity);

/**
 * Adds an item to the end of the list.
 *
 * @param instance the `List` instance.
 * @param item     the item to add.
 * @return An exception; otherwise `0`. This method always returns `0` if the
 *         current capacity is sufficient.
*/
Exception list_add(List instance, Object item);

/**
 * Ensures that the capacity of this list is at least the specified capacity.
 * If the current capacity is less than the required minimum capacity, it is
 * increased to at least the specified capacity.
 * 
 * @param instance the `List` instance.
 * @param capacity the required minimum capacity.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception list_ensure_capacity(List instance, size_t capacity);

/**
 * Determines whether an element is in the list. This method performs a linear
 * search.
 *
 * @param instance     the `List` instance.
 * @param item         the item to locate in the list.
 * @param itemComparer the comparer used to determine if two items are equal.
 * @return `true` if the `item` is found in the list; otherwise, `false`.
*/
bool list_contains(List instance, Object item, EqualityComparer itemComparer);

/**
 * Removes all elements from the list.
 * 
 * @param instance the `List` instance.
*/
void list_clear(List instance);

/**
 * Reverses the order of the elements in the list.
 * 
 * @param instance the `List` instance.
*/
void list_reverse(List instance);

/**
 * Sorts the elements in the list.
 * 
 * @param instance     the `List` instance.
 * @param itemComparer the comparer used to detemrine the sort order.
*/
void list_sort(List instance, Comparer itemComparer);

/**
 * Determines whether two lists are equal in sequence.
 * 
 * @param left         a list to compare to `right`. 
 * @param right        a list to compare to `left`.
 * @param itemComparer the comparer used to determine if two items are equal.
 * @return `true` if the two lists are of equal length and their corresponding
 *         elements are equal; otherwise, `false`.
*/
bool list_sequence_equal(List left, List right, EqualityComparer itemComparer);

/**
 * Frees all resources.
 *
 * @param instance the `List` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_list(List instance);

#endif
