// Licensed under the MIT License.

#include "../primality.h"

/**
 * Determines if a number is a prime using the Miller–Rabin primality test.
 * 
 * @param n the number to test.
 * @return `PRIMALITY_PRIME` if `n` is prime or `PRIMALITY_COMPOSITE` if `n` is
 *         composite; otherwise, `PRIMALITY_NONE`.
*/
Primality miller_rabin_primality_test(long n);
