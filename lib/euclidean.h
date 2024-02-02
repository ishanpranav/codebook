// Licensed under the MIT License.

/**
 * Computes the greatest common divisor using Euclid's algorithm.
 *
 * @param a a natural number.
 * @param b a natural number.
 * @return The greatest common divisor of `a` and `b`.
*/
long gcd(long a, long b);

/**
 * Computes the least common multiple using Euclid's algorithm.
 * 
 * @param a a natural number.
 * @param b a natural number.
 * @return The least common multiple of `a` and `b`.
*/
long lcm(long a, long b);

/**
 * Generates the number of Pythagorean triplets (unique `a`, `b`, and `c`) for
 * all sums `p` = `a` + `b` + `c` in the interval [0, `max`).
 * 
 * @param max the upper bound for the perimeter of the right triangles to
 *            consider.
 * @return A `max`-element array, or `NULL` if the process is out of
 *         memory. The caller is responsible.
*/
int* pythagorean_triplet_counts(long max);
