// Licensed under the MIT License.

#include "boolean_set.h"
#include "list.h"

/** Represents the sequence of all primes in the interval [2, `max`). */
struct PrimeList
{
    struct List primes;
    struct BooleanSet composites;
    long max;
};

/** Represents the sequence of all primes in the interval [2, `max`). */
typedef struct PrimeList* PrimeList;

/**
 * Initializes a `PrimeList` instance.
 *
 * @param instance the `PrimeList` instance.
 * @param max      the exclusive upper bound of the prime sequence.
 * @return The exception; otherwise, `0`.
*/
Exception prime_list(PrimeList instance, long max);

/**
 * Determines whether the given number is a prime. If `n` is in the interval
 * [2, `max`), this method searches for `n` in the internal data structure.
 * Otherwise, it uses an alternative algorithm for checking primes.
 * 
 * @param instance the `PrimeList` instance.
 * @param n        the number to test.
 * @return `true` if `n` is prime; otherwise, `false`.
*/
bool prime_list_is_prime(PrimeList instance, long n);

/**
 * Frees all resources.
 *
 * @param instance the `PrimeList` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_prime_list(PrimeList instance);
