// Licensed under the MIT License.

#include "lp_string.h"

/** Represents a series of decimal digits. */
struct Series
{
    char* begin;
    char* end;
};

/** Represents a series of decimal digits. */
typedef struct Series* Series;

/**
 * Initializes a `Series` instance.
 * 
 * @param instance the `Series` instance.
 * @param value    the string whose digits represent the elements in the series.
 *                 This method corrupts the `value` argument. The caller is
 *                 responsible for this argument.
*/
void series_from_string(Series instance, LPString value);

/**
 * Computes a summation of the elements in the series.
 * 
 * @param instance the `Series` instance.
 * @return The sum of the series.
*/
int series_sum(Series instance);
