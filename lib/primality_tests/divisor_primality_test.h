// Licensed under the MIT License.

#include "../primality.h"

/**
 * Determines if a number is a prime using trial division.
 * 
 * @param n the number to test.
 * @return `PRIMALITY_PRIME` if `n` is prime or `PRIMALITY_COMPOSITE` if `n` is
 *         composite; otherwise, `PRIMALITY_NONE`.
*/
Primality divisor_primality_test(long n);
