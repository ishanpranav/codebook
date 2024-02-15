// Licensed under the MIT License.

#include "object.h"
#include <stdbool.h>
#include <stddef.h>

/** Iterates over all unique `k`-element subsets of the interval [1, `n`]. */
struct CombinationIterator
{
    int* subset;
    int i;
    int k;
    int n;
    bool end;
};

/** Iterates over all unique `k`-element subsets of the interval [1, `n`]. */
typedef struct CombinationIterator* CombinationIterator;

/**
 * Provides an iterator over the unique `k`-element subsets of the interval
 * [1, `n`].
 * 
 * @param iterator when this method returns, contains the iterator. This
 *                 argument is passed uninitialized.
 * @param subset   when this method returns, contains the subset. This
 *                 argument is passed as an uninitialized `k`-element array for
 *                 which the caller is responsible.
 * @param n        the cardinality of the superset.
 * @param k        the cardinality of the subset.
*/
void combination_begin(
    CombinationIterator iterator,
    int subset[],
    int n,
    int k);

/**
 * Advances the iterator to the next unique `k`-element subset.
 * 
 * @param iterator the iterator.
*/
void combination_next(CombinationIterator iterator);
