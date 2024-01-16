// Licensed under the MIT License.

#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#define macro do {
#define end_macro } while (false)
#define euler_ok() macro \
if (ex) \
{ \
    fprintf(stderr, "Error: %d at %s line %d.\n", ex, __FILE__, __LINE__); \
    return ex; \
} \
end_macro

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
void euler_swap(long* p, long* q);

/**
 * Computes a partial summation of the natural numbers.
 *
 * @param n the number of terms in the sequence.
 * @return The sum of the first `n` natural numbers.
*/
long math_natural_sum(long n);

/**
 * Computes the greatest common divisor using Euclid's algorithm.
 *
 * @param a a natural number.
 * @param b a natural number.
 * @return The greatest common divisor of `a` and `b`.
*/
long math_gcd(long a, long b);

/**
 * Determines if a given value is a palindrome.
 *
 * @param n the value to test.
 * @return `true` if the `n` is a palindrome; otherwise, `false`.
*/
bool math_is_palindrome(long n);
