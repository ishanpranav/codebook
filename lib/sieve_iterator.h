// Licensed under the MIT License.

#include "sieve.h"

/** Provides an iterator over all primes. */
struct SieveIterator
{
    struct Sieve* values;
    long long* current;
};

/** Provides an iterator over all primes. */
typedef struct SieveIterator* SieveIterator;

/**
 * Provides an iterator over all primes.
 *
 * @param iterator the iterator.
 * @param values   the sieve whose elements to enumerate. This method may
 *                 dynamically extend the `values` argument.
*/
void sieve_begin(SieveIterator iterator, Sieve values);

/**
 * Advances the iterator by a given number of primes.
 *
 * @param iterator the iterator.
 * @param count    the number of iterations to skip. This method may dynamically
 *                 extend the `values` argument.
*/
void sieve_skip(SieveIterator iterator, long long count);

/**
 * Advances the iterator to the next prime.
 *
 * @param iterator the iterator.
*/
void sieve_next(SieveIterator iterator);
