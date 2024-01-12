// Licensed under the MIT license.

#include <stdbool.h>
#include <stddef.h>

struct PermutationIterator
{
    long* set;
    size_t length;
    bool end;
};

/** Iterates over the lexicographical permutations of a set. */
typedef struct PermutationIterator* PermutationIterator;

/**
 * Provides an iterator over the lexicographical permutations of a set.
 *
 * @param iterator the iterator.
 * @param set      the set.
 * @param length   the cardinality of the set.
*/
void permutation_begin(PermutationIterator iterator, long* set, size_t length);

/**
 * Advances the iterator to the next lexicographical permutation. This method
 * shuffles the `set` field of the `iterator` argument.
 * 
 * @param iterator the iterator.
*/
void permutation_next(PermutationIterator iterator);
