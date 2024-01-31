// Licensed under the MIT License.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define macro do {
#define end_macro } while (0)
#define euler_ok(ex) macro \
    Exception _ex = (ex); \
    if (_ex) { \
    fprintf(stderr, "Error: %d at %s line %d.\n", _ex, __FILE__, __LINE__); \
    exit(_ex); } end_macro
#define euler_assert(condition) macro if (!(condition)) { \
    fprintf(stderr, "Faulted: %s line %d.\n", __FILE__, __LINE__); \
    exit(1); } end_macro
#define math_concat(left, ...) math_concat_impl(left, __VA_ARGS__, 0);

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
 * Computes a partial summation of the natural numbers. This is equivalent to
 * computing the `n`-th triangular number.
 *
 * @param n the number of terms in the sequence.
 * @return The sum of the first `n` natural numbers.
*/
long math_natural_sum(long n);

/**
 * Determines the number of digits in the number resulting from `b` raised to
 * the power `a`.
 * 
 * @param b the base.
 * @param a the exponent.
 * @return The number of digits in the expanded expression `b^a`.
*/
long long math_length(long long b, long long a);

/**
 * Concatenates a span of zero-terminated integers.
 * 
 * @param left  the left digits.
 * @param right the first segment of right digits.
 * @return An integer formed by writing out the digits of `left` immediately
 *         followed by the digits of `right`, then followed by any additional
 *         integers in the order specified.
*/
unsigned long long math_concat_impl(int left, int right, ...);

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
