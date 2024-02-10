// Licensed under the MIT License.

#include <stddef.h>
#include "array.h"
#include "comparer.h"

/** Defines a sorting algorithm. */
typedef void (*Sort)(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer);

/**
 * Sorts a collection using the bubble sort algorithm.
 * 
 * @param items        the collection of items.
 * @param count        the number of items.
 * @param itemSize     the size of each item.
 * @param itemComparer the item comparer.
*/
void bubble_sort(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer);

/**
 * Sorts a collection using the selection sort algorithm.
 * 
 * @param items        the collection of items.
 * @param count        the number of items.
 * @param itemSize     the size of each item.
 * @param itemComparer the item comparer.
*/
void selection_sort(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer);

/**
 * Sorts a collection using the insertion sort algorithm.
 * 
 * @param items        the collection of items.
 * @param count        the number of items.
 * @param itemSize     the size of each item.
 * @param itemComparer the item comparer.
*/
void insertion_sort(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer);

/**
 * Sorts a collection using the merge sort algorithm.
 * 
 * @param items        the collection of items.
 * @param count        the number of items.
 * @param itemSize     the size of each item.
 * @param itemComparer the item comparer.
*/
void merge_sort(
    Array items,
    size_t count,
    size_t itemSize,
    Comparer itemComparer);
