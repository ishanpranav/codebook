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
 * Returns the `n`-th prime. The `n`-th prime is approximately `n log n`.
 * For convenience, `n` is a zero-based index.
 * 
 * @param instance the `Sieve` instance.
 * @param n        the zero-based term number in the prime sequence.
 * @return The `n`-th prime.
*/
long long sieve_prime(Sieve instance, size_t n);

/**
 * Determines if a number is a prime.
 *
 * @param instance the `Sieve` instance.
 * @param n        the number to test.
 * @param fallback `NULL` or a fallback algorithm for determining if a number is
 *                 a prime. The `fallback` argument may be used if `n` is
 *                 outside the interval [2, `max`).
 * @return The supposed primality of `n`.
*/
Primality sieve_test(Sieve instance, long long n, PrimalityTest fallback);

/**
 * Frees all resources.
 *
 * @param instance the `Sieve` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_sieve(Sieve instance);
