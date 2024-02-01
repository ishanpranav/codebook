// Licensed under the MIT License.

#include <stddef.h>
#include "array.h"
#include "comparer.h"
#include "exception.h"

/** Defines an algorithm that a type implements to merge two sorted arrays. */
typedef Exception (*Merge)(
    Array result,
    Array left,
    size_t leftLength,
    Array right,
    size_t rightLength,
    size_t itemSize,
    Comparer itemComparer);

/**
 * 
 * @param left
 * @param leftLength
 * @param right
 * @param rightLength
 * @param itemSize
 * @return
*/
Exception merge(
    Array result,
    Array left,
    size_t leftLength,
    Array right,
    size_t rightLength,
    size_t itemSize,
    Comparer itemComparer);

/**
 * 
 * @param left
 * @param leftLength
 * @param right
 * @param rightLength
 * @param itemSize
 * @return 
*/
Exception inplace_merge(
    Array result,
    Array left,
    size_t leftLength,
    Array right,
    size_t rightLength,
    size_t itemSize,
    Comparer itemComparer);
