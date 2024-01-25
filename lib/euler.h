// Licensed under the MIT License.

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#define macro do {
#define end_macro } while (false)
#define euler_ok() macro if (ex) { \
    fprintf(stderr, "Error: %d at %s line %d.\n", ex, __FILE__, __LINE__); \
    return ex; \
} end_macro

/**
 * Submits a solution for the problem with the given identifier.
 *
 * @param id     the problem identifier.
 * @param result the solution.
 * @param start  the program start time.
 * @return `0` always.
*/
int euler_submit(int id, long long result, clock_t start);

/**
 * Exchanges the given values.
 *
 * @param p a pointer to the first element to swap
 * @param q a pointer to the second element to swap
*/
void euler_swap(long long* p, long long* q);

/**
 * Computes a partial summation of the natural numbers. This is equivalent to
 * computing the `n`-th triangular number.
 *
 * @param n the number of terms in the sequence.
 * @return The sum of the first `n` natural numbers.
*/
long math_natural_sum(long n);

/**
 * Computes the binomial coefficient `n` "choose" `k`.
 * 
 * @param n the cardinality of the superset.
 * @param k the cardinality of the subset.
 * @return The number of `k`-element combinations (subsets) that can be chosen
 *         from an `n`-element set.
*/
long long math_binomial(int n, int k);

/**
 * Computes the greatest common divisor using Euclid's algorithm.
 *
 * @param a a natural number.
 * @param b a natural number.
 * @return The greatest common divisor of `a` and `b`.
*/
long math_gcd(long a, long b);

/**
 * Determines the number of digits in the number resulting from `b` raised to
 * the power `a`.
 * 
 * @param b the base.
 * @param a the exponent.
 * @return The number of digits in the expanded expression `b^a`.
*/
int math_length(int b, int a);

/**
 * Reverses the digits of a given value.
 * 
 * @param n the value to reverse.
 * @return the reflection of `n`.
*/
long long math_reverse(long long n);

/**
 * Determines if a given value is a palindrome.
 *
 * @param n the value to test.
 * @return `true` if `n` is a palindrome; otherwise, `false`.
*/
bool math_is_palindrome(long long n);

/**
 * Determines if a given value is a polygonal number.
 * 
 * @param s       the number of sides of the polygon.
 * @param x       the value to test.
 * @param approxN when this method returns, contaisn an approximation for `n`,
 *                where `x` is the `n`-th `s`-gonal number. This argument is
 *                passed uninitialized, or `NULL` if the value will not be used.
 * @return `true` if `x` is a `s`-gonal number; otherwise, `false`.
*/
bool math_is_polygonal(int s, long x, long* approxN);
