// Licensed under the MIT License.

#include "primality.h"

/** Defines a method for determining the primality of a number. */
typedef enum Primality (*PrimalityTest)(long n);

/**
 * Determines if a number is a prime using trial division.
 * 
 * @param n the number to test.
 * @return `PRIMALITY_PRIME` if `n` is prime or `PRIMALITY_COMPOSITE` if `n` is
 *         composite; otherwise, `PRIMALITY_NONE`.
*/
Primality divisor_primality_test(long n);

/**
 * Determines if a number is a prime using the Miller–Rabin primality test.
 * 
 * @param n the number to test.
 * @return `PRIMALITY_PRIME` if `n` is prime or `PRIMALITY_COMPOSITE` if `n` is
 *         composite; otherwise, `PRIMALITY_NONE`.
*/
Primality miller_rabin_primality_test(long n);
