// Licensed under the MIT License.

#include <stdbool.h>
#include "divisor_iterator_state.h"

/** Iterates over the proper divisors of a natural number. */
struct DivisorIterator
{
    long long n;
    long long current;
    long long next;
    long long end;
    enum DivisorIteratorState state;
};

/** Iterates over the proper divisors of a natural number. */
typedef struct DivisorIterator* DivisorIterator;

/**
 * Provides an iterator over the proper divisors of `n`.
 * 
 * @param iterator when this method returns, contains the iterator. This
 *                 argument is passed uninitialized.
 * @param n        the number whose divisors to enumerate.
*/
void divisor_begin(DivisorIterator iterator, long long n);

/**
 * Returns a value indicating whether the iterator can advance to the next
 * proper divisor.
 * 
 * @param iterator the iterator.
 * @return `true` if the iterator can successfully advance to the next divisor;
 *         `false` if there are no more divisors.
*/
bool divisor_end(DivisorIterator iterator);

/**
 * Advances the iterator to the next proper divisor.
 * 
 * @param iterator the iterator.
*/
void divisor_next(DivisorIterator iterator);
