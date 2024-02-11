// Licensed under the MIT License.

#include <stddef.h>
#include "array.h"
#include "comparer.h"
#include "object.h"

/**
 * Searches a sorted for the first element greater than a given value in a
 * sorted collection. This function uses the binary search algorithm.
 *
 * @param item     the required minimum value.
 * @param items    the sorted collection of items.
 * @param length   the number of items.
 * @param itemSize the size of each item.
 * @param comparer the item comparer. The `items` argument must be sorted
 *                 using the same comparer.
*/
Object binary_search_first_after(
    Object item,
    Array items,
    size_t length,
    size_t itemSize,
    Comparer comparer);
