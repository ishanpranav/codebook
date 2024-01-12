// Licensed under the MIT License.

#include <stdbool.h>

/**  Specifies a divisor iterator's state. */
enum DivisorIteratorState
{
    /** The initial state. */
    DIVISOR_ITERATOR_STATE_INITIAL,

    /** The state during which the iterator checks the next pair of divisors. */
    DIVISOR_ITERATOR_STATE_SWAP,

    /** The state during which the iterator provides a paired divisor. */
    DIVISOR_ITERATOR_STATE_YIELD
};

/** Iterates over the proper divisors of a natural number. */
struct DivisorIterator
{
    long n;
    long current;
    long next;
    long end;
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
void divisor_begin(DivisorIterator iterator, long n);

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
long divisor_sum(long n);
