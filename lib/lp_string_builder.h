// Licensed under the MIT License.

#include <stdbool.h>
#include <stddef.h>
#include "exception.h"
#include "lp_string.h"

/** Represents a mutable string of characters. */
struct LPStringBuilder
{
    char* buffer;
    size_t length;
    size_t capacity;
};

/** Represents a mutable string of characters. */
typedef struct LPStringBuilder* LPStringBuilder;

/**
 * Initializes an `LPStringBuilder` instance.
 * 
 * @param instance the `LPStringBuilder` instance.
 * @param capacity the required minimum capacity.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception lp_string_builder(LPStringBuilder instance, size_t capacity);

void lp_string_builder_from_string(LPStringBuilder instance, LPString value);

/**
 * Appends a specified char to this instance.
 * 
 * @param instance the `LPStringBuilder` instance.
 * @param value    the char value.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception lp_string_builder_append_char(LPStringBuilder instance, char value);

Exception lp_string_builder_append_string(LPStringBuilder instance, LPString value);

Exception lp_string_builder_append_format(
    LPStringBuilder instance, 
    LPString format,
    ...);

/**
 * Removes all characters from this instance.
 * 
 * @param instance the `LPStringBuilder` instance.
*/
void lp_string_builder_clear(LPStringBuilder instance);

/**
 * Converts the value of an `LPStringBuilder` to a new `LPString`.
 * 
 * @param instance the `LPStringBuilder` instance.
 * @return A new string whose value is the same as this instance. The caller is
 *         responsible.
*/
LPString lp_string_builder_to_string(LPStringBuilder instance);

/**
 * Determines whether two `LPStringBuilders` represent the same string value.
 * 
 * @param left  a string builder to compare to `right`. 
 * @param right a string builder to compare to `left`.
 * @return `true` if the two string builders represent the same string values;
 *         otherwise, `false`.
*/
bool lp_string_builder_equals(LPStringBuilder left, LPStringBuilder right);

/**
 * Frees all resources.
 * 
 * @param instance the `LPStringBuilder` instance. This method corrupts the
 *                 `instance` argument.
*/
void finalize_lp_string_builder(LPStringBuilder instance);
