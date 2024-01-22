// Licensed under the MIT License.

#include "boolean_set.h"
#include "list.h"
#include "object.h"
#include "primality_test.h"

/** Represents the sequence of all primes in the interval [2, `max`). */
struct Sieve
{
    struct List primes;
    struct BooleanSet composites;
    long max;
};

struct SieveIterator
{
    struct Sieve* values;
    long* current;
};

/** Represents the sequence of all primes in the interval [2, `max`). */
typedef struct Sieve* Sieve;

typedef struct SieveIterator* SieveIterator;

/**
 * Initializes a `Sieve` instance.
 *
 * @param instance the `Sieve` instance.
 * @param max      the exclusive minimum upper bound of the prime sequence.
 * @return The exception; otherwise, `0`.
*/
Exception sieve(Sieve instance, long max);

void sieve_begin(SieveIterator iterator, Sieve values);
void sieve_skip(SieveIterator iterator, long count);
void sieve_next(SieveIterator iterator);

Primality sieve_test(Sieve instance, long n, PrimalityTest fallback);

/**
 * Frees all resources.
 *
 * @param instance the `Sieve` instance. This method corrupts the `instance`
 *                 argument.
*/
void finalize_sieve(Sieve instance);
