// Licensed under the MIT License.

#include <stddef.h>
#include "array.h"
#include "comparer.h"
#include "object.h"

/**
 * Searches a sorted collection for the least element greater than or equal to
 * a given value. This function uses the binary search algorithm.
 *
 * @param min      the required minimum value.
 * @param items    the sorted collection of items.
 * @param length   the number of items.
 * @param itemSize the size of each item.
 * @param comparer the item comparer. The `items` argument must be sorted
 *                 using the same comparer.
 * @return A reference to the least element greater than or equal to the
 *         given minimum.
*/
Object binary_search_min(
    Object min,
    Array items,
    size_t length,
    size_t itemSize,
    Comparer comparer);

/**
 * Determines the number of elements less than a given value in a sorted
 * collection. This function uses the binary search algorithm.
 * 
 * @param max      the required maximum value.
 * @param items    the sorted collection of items.
 * @param length   the number of items.
 * @param itemSize the size of each item.
 * @param comparer the item comparer. The `items` argument must be sorted using
 *                 the same comparer.
 * @return The number of items less than the given maximum.
*/
size_t binary_search_rank(
    Object max,
    Array items,
    size_t length,
    size_t itemSize,
    Comparer comparer);
