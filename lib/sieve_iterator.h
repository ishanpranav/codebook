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
 * Advances the iterator to the first prime greater than or equal to a given
 * minimum.
 * 
 * @param iterator the iterator.
 * @param min      the required minimum value.
*/
void sieve_jump(SieveIterator iterator, long long min);

/**
 * Advances the iterator by a given number of primes.
 *
 * @param iterator the iterator.
 * @param count    the number of iterations to skip. This method may dynamically
 *                 extend the `values` argument.
*/
void sieve_skip(SieveIterator iterator, size_t count);

/**
 * Advances the iterator to the next prime.
 *
 * @param iterator the iterator.
*/
void sieve_next(SieveIterator iterator);
