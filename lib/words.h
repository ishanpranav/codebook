// Licensed under the MIT License.

#include "euler.h"

/**
 * Converts a non-negative integer into its English string representaiton.
 * 
 * @param value the integral value.
 * @return Fully expanded English string representation of the given value, or
 *         `NULL` if there is not enough memory to complete the operation. The
 *         caller is responsible.
*/
String words_to_string(int value);

/**
 * Solves Project Euler Problem 17 (Number Letter Counts) by computing the total
 * number of letters in the formal English string representation of the first
 * one thousand positive integers.
 * 
 * @return The solution to Project Euler Problem 17.
*/
int words_number_letter_counts(void);
