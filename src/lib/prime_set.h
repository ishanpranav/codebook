#include <stdbool.h>

struct PrimeSet
{
    bool* composites;
    long max;
};

struct PrimeSetIterator
{
    struct PrimeSet* set;
    long current;
};

/** Represents the set of prime numbers less than an exclusive upper bound. */
typedef struct PrimeSet* PrimeSet;

/** Provides an enumerator for the `PrimeSet` class. */
typedef struct PrimeSetIterator* PrimeSetIterator;

/**
 * Initializes an instance of the `PrimeSet` class.
 *
 * This method initializes `instance` with all prime numbers in the interval
 * `[2, max)`.
 *
 * @param instance the `PrimeSet` instance.
 * @param max      the exclusive upper bound.
 * @return `true` if the instance was initialized successfully; `false` if the
 *         process is out of memory.
*/
bool prime_set(PrimeSet instance, long max);

/**
 * Initializes an enumerator that iterates through the `PrimeSet`.
 *
 * @param instance the `PrimeSet` instance.
 * @param iterator the `PrimeSetIterator` instance.
*/
void prime_set_begin(PrimeSet instance, PrimeSetIterator iterator);

/**
 * Returns a value indicating whether the upper bound has been reached.
 *
 * @param instance the `PrimeSetIterator` instance.
 * @return `true` if the enumerator has passed the end of the `PrimeSet`;
 *         otherwise, `false`.
*/
bool prime_set_end(PrimeSetIterator iterator);

/**
 * Advances the enumerator to the next prime number.
 *
 * @param instance the `PrimeSetIterator` instance.
*/
void prime_set_next(PrimeSetIterator iterator);

/**
 * Frees all resources used by the object.
 * 
 * @param instance the `PrimeSet` instance
*/
void finalize_prime_set(PrimeSet instance);
