// Licensed under the MIT License.

#include <stdint.h>
#include "object.h"

/** Defines a random number generator. */
typedef long long (*Random)(void* instance, long long max);

/**
 * Generates a random integer in the interval [0, `max`) using Blackman and
 * Vigna's xoshiro256** (exclusive or-shift-rotate, 256-bit) algorithm.
 *
 * @param instance the instance.
 * @param max      the exclusive upper bound of the generated integer.
 * @return A random integer in the interval [0, `max`). Only the least 64 bits
 *         of this value are necessarily uniformly distributed.
*/
long long xoshiro256_star_star_random(Object instance, long long max);

/**
 * Generates a random 64-bit integer using Blackman and Vigna's xoshiro256**
 * (exclusive or-shift-rotate, 256-bit) algorithm, and returns a value truncated
 * to exactly 64 bits.
 *
 * @param instance the instance.
 * @return A uniformly-distributed random 64-bit integer in the interval.
*/
uint64_t xoshiro256_star_star_random64(Object instance);

/**
 * Generates a random integer in the interval [0, `max`] using Marsaglia's
 * xorshift32 (exclusive or, 32-bit) algorithm.
 *
 * @param instance the instance.
 * @param max      the exclusive upper bound of the generated integer.
 * @return A random integer in the interval [0, `max`]. Only the least 32 bits
 *         of this value are necessarily uniformly distributed.
*/
long long xorshift32_random(Object instance, long long max);

/**
 * Generates a random 32-bit integer in the interval [0, `max`] using
 * Marsaglia's xorshift32 (exclusive or, 32-bit) algorithm.
 *
 * @param instance the instance.
 * @return A uniformly distributed random 32-bit integer in the interval.
*/
uint32_t xorshift32_random32(Object instance);
