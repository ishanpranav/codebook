// Licensed under the MIT License.

/**
 * Generates the number of Pythagorean triplets (unique `a`, `b`, and `c`) for
 * all sums `p` = `a` + `b` + `c` in the interval [0, `max`).
 * 
 * @param max the upper bound for the perimeter of the right triangles to
 *            consider.
 * @return A `max`-element array, or `NULL` if the process is out of
 *         memory. The caller is responsible.
*/
int* pythagorean_triplet_count_range(long max);
