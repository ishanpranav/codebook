// Licensed under the MIT License.

/**
 * Computes the binomial coefficient `n` "choose" `k`.
 * 
 * @param n the cardinality of the superset.
 * @param k the cardinality of the subset.
 * @return The number of `k`-element combinations (subsets) that can be chosen
 *         from an `n`-element set.
*/
long long binomial(int n, int k);

/**
 * Generates values of the binomial coefficient `n` "choose" `k` mod `mod` for
 * all `k` in the interval [0, `n`].
 * 
 * @param n   the cardinality of the superset.
 * @param mod the modulus, or `0` for the default modulus. 
 * @return A (`n` + 1)-element array, or `NULL` if the process is out of
 *         memory. The caller is responsible.
*/
long long* binomial_mod_range(int n, long long mod);
