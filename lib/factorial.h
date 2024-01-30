// Licensed under the MIT License.

#include "array.h"

/**
 * Generates values of the factorial function for all inputs in the interval
 * [0, `max`).
 * 
 * @param max the exclusive upper bound of the input range.
 * @return A `max`-element array, or `NULL` if the process is out of memory. The
 *         caller is responsible.
*/
long long* factorial_range(int max);
