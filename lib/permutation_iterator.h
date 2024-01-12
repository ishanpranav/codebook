// Licensed under the MIT license.

#include <stdbool.h>
#include <stddef.h>
#include "list.h"

/** Iterates over the lexicographical permutations of a collection. */
struct PermutationIterator
{
    List values;
    bool end;
};

/** Iterates over the lexicographical permutations of a collection. */
typedef struct PermutationIterator* PermutationIterator;

/**
 * Provides an iterator over the lexicographical permutations of a collection.
 *
 * @param iterator the iterator.
 * @param values   the collection.
*/
void permutation_begin(PermutationIterator iterator, List values);

/**
 * Advances the iterator to the next lexicographical permutation. This method
 * shuffles the `set` field of the `iterator` argument.
 * 
 * @param iterator the iterator.
*/
void permutation_next(PermutationIterator iterator);
