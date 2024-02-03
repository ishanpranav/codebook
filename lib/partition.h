// Licensed under the MIT License.

/**
 * Generates values of the restricted partition function for all inputs in the
 * interval [0, `max`).
 * 
 * @param max         the exclusive upper bound of the input range.
 * @param constraints the set of constraints; that is, the elements which may be
 *                    used as addends summing to `n` when computing `p(n)`.
 * @param length      the cardinality of the constraints set.
 * @return A `max`-element array, or `NULL` if the process is out of memory. The
 *         caller is responsible.
*/
int* restricted_partition_range(int max, int constraints[], int length);
