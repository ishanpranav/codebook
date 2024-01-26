// Licensed under the MIT License.

#include "sieve_iterator.h"

/** Iterates over the prime factors of a positive integer. */
struct FactorIterator
{
    struct SieveIterator iterator;
    long long current;
    long long remainder;
    int currentCount;
};

/** Iterates over the prime factors of a positive integer. */
typedef struct FactorIterator* FactorIterator;

/**
 * Provides an iterator over the prime factors of `n`.
 * 
 * @param iterator the iterator.
 * @param n        the number whose factors to enumerate.
 * @param primes   the prime sequence.
*/
void factor_begin(FactorIterator iterator, long long n, Sieve primes);

/**
 * Returns a value indicating whether the iterator can advance to the next prime
 * factor.
 * 
 * @param iterator the iterator.
 * @return `true` if the iterator can successfully advance to the next factor;
 *         `false` if there are no more factors.
*/
bool factor_end(FactorIterator iterator);

/**
 * Advances the iterator to the next prime factor.
 * 
 * @param iterator the iterator.
*/
void factor_next(FactorIterator iterator);

/**
 * Returns the number of divisors of a positive integer.
 * 
 * @param n      the number whose divisors to count.
 * @param primes the prime sequence.
 * @return The number of divisors of `n`.
*/
int factor_divisor_count(long long n, Sieve primes);

/**
 * Computes the sum of the divisors of a positive integer.
 * 
 * @param n      the number whose divisors to sum.
 * @param primes the prime sequence.
 * @return The sum of the divisors of `n`.
*/
int factor_divisor_sum(long long n, Sieve primes);
