// Licensed under the MIT License.

/**
 * Generates values of the partition function for all inputs in the interval
 * [0, `max`). This method uses a simple algorithm to compute partitions, which
 * is appropriate for small values of `max`. For improved performance with large
 * values of `p(n)`, including those exceeding `2^64`, use
 * `mod_partition_range`.
 * 
 * @param max the exclusive upper bound of the input range.
 * @return A `max`-element array, or `NULL` if the process is out of memory. The
 *         caller is responsible.
*/
long* partition_range(long max);

/**
 * Generates values of the partition function modulo `mod` for all inputs in the
 * interval [0, `max`). This method uses the pentagonal number theorem to
 * compute partitions, which is appropriate for large values of `p(n)`,
 * including those exceeding `2^64`. For optimal performance with small values
 * of `max`, use `partition_range`.
 * 
 * @param max the exclusive upper bound of the input range.
 * @param mod the modulus, or `0` for the default modulus.
 * @return A `max`-element array, or `NULL` if the process is out of memory. The
 *         caller is responsible.
*/
long long* mod_partition_range(long max, long long mod);

/**
 * Generates values of the restricted partition function for all inputs in the
 * interval [0, `max`), using only a constrained set of legal addends.
 * 
 * @param max         the exclusive upper bound of the input range.
 * @param constraints the set of constraints; that is, the elements which may be
 *                    used as addends summing to `n` when computing `p(n)`.
 * @param length      the cardinality of the constraints set.
 * @return A `max`-element array, or `NULL` if the process is out of memory. The
 *         caller is responsible.
*/
long long* restricted_partition_range(
    long max, 
    long long constraints[], 
    long length);
