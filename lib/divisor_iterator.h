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
 * Provides an iterator over the divisors of `n`.
 * 
 * @param iterator the iterator.
 * @param n        the number whose proper divisors to enumerate.
*/
void divisor_begin(DivisorIterator iterator, long long n);

/**
 * Returns a value indicating whether the iterator can advance to the next
 * divisor.
 * 
 * @param iterator 
 * @return `true` if the iterator can successfully advance to the next divisor;
 *         `false` if there are no more divisors.
*/
bool divisor_end(DivisorIterator iterator);

/**
 * Advances the iterator to the next divisor.
 * 
 * @param iterator the iterator.
*/
void divisor_next(DivisorIterator iterator);

/**
 * Computes the sum of the proper divisors of a natural number.
 * 
 * @param n the number whose proper divisors to sum.
 * @return The sum of the proper divisors of `n`.
*/
long long divisor_sum(long long n);
