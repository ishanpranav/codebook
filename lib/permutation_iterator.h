// Licensed under the MIT license.

#include <stdbool.h>
#include <stddef.h>
#include "list.h"

/** Iterates over the lexicographical permutations of a collection. */
struct PermutationIterator
{
    int (*itemComparer)(const void* left, const void* right);

    struct List* values;
    bool end;
};

/** Iterates over the lexicographical permutations of a collection. */
typedef struct PermutationIterator* PermutationIterator;

/**
 * Provides an iterator over the lexicographical permutations of a collection.
 *
 * @param iterator     the iterator.
 * @param values       the collection.
 * @param itemComparer the comparer used to determine the lexicographical order.
*/
void permutation_begin(
    PermutationIterator iterator,
    List values,
    Comparer itemComparer);

/**
 * Advances the iterator to the next lexicographical permutation. This method
 * shuffles the `set` field of the `iterator` argument.
 * 
 * @param iterator the iterator.
*/
void permutation_next(PermutationIterator iterator);

/**
 * Determines whether two collections are permutations of one another.
 * 
 * @param left         a collection to compare to `right`.
 * @param right        a collection to compare to `left`.
 * @param itemComparer the comparer used to determine if two elements are equal.
 * @return `true` if `left` and `right` are permutations; otherwise, `false`.
*/
bool permutation_test(List left, List right, EqualityComparer itemComparer);
