// Licensed under the MIT License.

#include <stdbool.h>
#include <stddef.h>
#include "exception.h"
#include "string.h"

/** Represents a mutable string of characters. */
struct StringBuilder
{
    char* buffer;
    size_t length;
    size_t capacity;
};

/** Represents a mutable string of characters. */
typedef struct StringBuilder* StringBuilder;

/**
 * Initializes an `StringBuilder` instance.
 * 
 * @param instance the `StringBuilder` instance.
 * @param capacity the required minimum capacity.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception string_builder(StringBuilder instance, size_t capacity);

void string_builder_from_string(StringBuilder instance, String value);

/**
 * Appends a specified char to this instance.
 * 
 * @param instance the `StringBuilder` instance.
 * @param value    the char value.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception string_builder_append_char(StringBuilder instance, char value);

Exception string_builder_append_string(StringBuilder instance, String value);

Exception string_builder_append_format(
    StringBuilder instance, 
    String format,
    ...);

/**
 * Removes all characters from this instance.
 * 
 * @param instance the `StringBuilder` instance.
*/
void string_builder_clear(StringBuilder instance);

/**
 * Converts the value of an `StringBuilder` to a new `String`.
 * 
 * @param instance the `StringBuilder` instance.
 * @return A new string whose value is the same as this instance. The caller is
 *         responsible.
*/
String string_builder_to_string(StringBuilder instance);

/**
 * Determines whether two `StringBuilders` represent the same string value.
 * 
 * @param left  a string builder to compare to `right`. 
 * @param right a string builder to compare to `left`.
 * @return `true` if the two string builders represent the same string values;
 *         otherwise, `false`.
*/
bool string_builder_equals(StringBuilder left, StringBuilder right);

/**
 * Frees all resources.
 * 
 * @param instance the `StringBuilder` instance. This method corrupts the
 *                 `instance` argument.
*/
void finalize_string_builder(StringBuilder instance);
