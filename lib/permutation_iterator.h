// Licensed under the MIT license.

#include <stdbool.h>
#include <stddef.h>
#include "array.h"
#include "comparer.h"
#include "equality_comparer.h"

/** Iterates over the lexicographical permutations of a collection. */
struct PermutationIterator
{
    int (*itemComparer)(const void* left, const void* right);

    void* items;
    size_t length;
    size_t itemSize;
    bool end;
};

/** Iterates over the lexicographical permutations of a collection. */
typedef struct PermutationIterator* PermutationIterator;

/**
 * Provides an iterator over the lexicographical permutations of a collection.
 *
 * @param iterator     when this method returns, contains the iterator. This
 *                     argument is passed uninitialized.
 * @param items        the collection.
 * @param length       the length of the `items` collection.
 * @param itemSize     the size of each element in `items`.
 * @param itemComparer the comparer used to determine the lexicographical order.
*/
void permutation_begin(
    PermutationIterator iterator,
    Array items,
    size_t length,
    size_t itemSize,
    Comparer itemComparer);

/**
 * Advances the iterator to the next lexicographical permutation. This method
 * shuffles the `items` field of the `iterator` argument.
 * 
 * @param iterator the iterator.
*/
void permutation_next(PermutationIterator iterator);

/**
 * Determines whether two collections are permutations of one another.
 * 
 * @param left         a collection to compare to `right`.
 * @param leftLength   the number of items in the `left` collection.
 * @param right        a collection to compare to `left`.
 * @param rightLength  the number of items in the `right` collection.
 * @param itemSize     the size of each element in `left` and `right`.
 * @param itemComparer the comparer used to determine if two elements are equal.
 * @return `true` if `left` and `right` are permutations; otherwise, `false`.
*/
bool permutation_test(
    Array left,
    size_t leftLength,
    Array right,
    size_t rightLength,
    size_t itemSize,
    EqualityComparer itemComparer);
