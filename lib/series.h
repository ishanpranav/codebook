#include "lp_string.h"

struct Series
{
    char* begin;
    char* end;
};

/** Represents a series of decimal digits. */
typedef struct Series* Series;

/**
 * Initializes a new instance of the `Series` type.
 * 
 * This method corrupts the `value` argument but does not take responsibility
 * for it.
 * 
 * @param value the string whose digits represent the elements in the series.
 *              This method corrupts the `value` argument. The caller is
 *              responsible for this argument.
 * @return A new `Series` instance. The caller is responsible.
*/
Series series_from_string(LPString value);

/**
 * Computes a summation of the elements in the series.
 * 
 * @param instance the `Series` instance.
 * @return The sum of the series.
*/
int series_sum(Series instance);
