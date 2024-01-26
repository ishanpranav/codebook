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
    long long max;
};

/** Represents the sequence of primes in a superset of [2, `max`). */
typedef struct Sieve* Sieve;

/**
 * Initializes a `Sieve` instance.
 *
 * @param instance the `Sieve` instance.
 * @param max      the exclusive minimum upper bound of the prime sequence.
 * @return The exception; otherwise, `0`.
*/
Exception sieve(Sieve instance, long long max);

/**
 * Determines if a number is a prime.
 *
 * @param instance the `Sieve` instance.
 * @param n        the number to test.
 * @param fallback a fallback algorithm for determining if a number is a prime.
 *                 The `fallback` argument is used if `n` is outside the
 *                 interval [2, `max`).
*/
Primality sieve_test(Sieve instance, long long n, PrimalityTest fallback);

/**
 * Frees all resources.
 *
 * @param instance the `Sieve` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_sieve(Sieve instance);
