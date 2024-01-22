// Licensed under the MIT License.

#include "boolean_set.h"
#include "list.h"
#include "object.h"
#include "primality_test.h"

/** Represents the sequence of primes in a superset of [2, `max`). */
struct Sieve
{
    struct List primes;
    struct BooleanSet composites;
    long max;
};

/** Provides an iterator over all primes. */
struct SieveIterator
{
    struct Sieve* values;
    long* current;
};

/** Represents the sequence of primes in a superset of [2, `max`). */
typedef struct Sieve* Sieve;

/** Provides an iterator over all primes. */
typedef struct SieveIterator* SieveIterator;

/**
 * Initializes a `Sieve` instance.
 *
 * @param instance the `Sieve` instance.
 * @param max      the exclusive minimum upper bound of the prime sequence.
 * @return The exception; otherwise, `0`.
*/
Exception sieve(Sieve instance, long max);

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
void sieve_skip(SieveIterator iterator, long count);

/**
 * Advances the iterator to the next prime.
 *
 * @param iterator the iterator.
*/
void sieve_next(SieveIterator iterator);

/**
 * Determines if a number is a prime.
 *
 * @param instance the `Sieve` instance.
 * @param n        the number to test.
 * @param fallback a fallback algorithm for determining if a number is a prime.
 *                 The `fallback` argument is used if `n` is outside the
 *                 interval [2, `max`).
*/
Primality sieve_test(Sieve instance, long n, PrimalityTest fallback);

/**
 * Frees all resources.
 *
 * @param instance the `Sieve` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_sieve(Sieve instance);
