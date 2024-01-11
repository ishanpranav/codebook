// Licensed under the MIT License.

#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#define euler_throw(error) do \
{ \
    fprintf(stderr, "Error: " error " at %s line %d.\n", __FILE__, __LINE__); \
    return 1; \
} while (0)

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
 * Computes a partial summation of the natural numbers.
 *
 * @param n the number of terms in the sequence.
 * @return The sum of the first `n` natural numbers.
*/
long math_natural_sum(long n);
