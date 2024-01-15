// Licensed under the MIT License.

#ifndef _95a94c0379b44bd3967523c81d4caa55
#define _95a94c0379b44bd3967523c81d4caa55
#include <stddef.h>
#include "exception.h"

/** Represents a list of integers that can be accessed by index. */
struct List
{
    long* begin;
    long* end;
    size_t capacity;
};

/** Represents a list of integers that can be accessed by index. */
typedef struct List* List;

/**
 * Initializes a `List` instance.
 *
 * @param instance the `List` instance.
 * @param capacity the capacity.
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
void list_from_array(List instance, long values[], size_t length);

/**
 * Adds an item to the end of the list.
 *
 * @param instance the `List` instance.
 * @param item     the item to add.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception list_add(List instance, long item);

/**
 * Determines whether an element is in the list.
 *
 * @param instance the `List` instance.
 * @param item     the item to locate in the list.
 * @return `true` if the `item` is found in the list; otherwise, `false`.
*/
bool list_contains(List instance, long item);

/**
 * Removes all elements from the list.
 * 
 * @param instance the `List` instance.
*/
void list_clear(List instance);

/**
 * Frees all resources.
 *
 * @param instance the `List` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_list(List instance);

#endif
