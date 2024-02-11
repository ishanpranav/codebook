// Licensed under the MIT License.

#include <stdbool.h>
#include <stddef.h>
#include "euler.h"
#include "object.h"

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

/**
 * Initializes a static `StringBuilder` instance using the specified string. Do
 * not call `finalize_string_builder`.
 * 
 * @param instance the `StringBuilder` instance.
 * @param value    the backing string for the builder. The caller is responsible
 *                 for this argument.
*/
void string_builder_from_string(StringBuilder instance, String value);

/**
 * 
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception string_builder_copy(
    StringBuilder result, 
    StringBuilder instance);

/**
 * Ensures that the capacity of this instance of `StringBuilder` is at least the
 * specified value.
 * 
 * @param instance the `StringBuilder` instance.
 * @param value    the required minimum capacity.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception string_builder_ensure_capacity(
    StringBuilder instance,
    size_t capacity);

/**
 * Appends a specified char to this instance.
 * 
 * @param instance the `StringBuilder` instance.
 * @param value    the char to append.
 * @return An exception; otherwise, `0`.
*/
Exception string_builder_append_char(StringBuilder instance, char value);

/**
 * Appends a copy of the specified string to this instance.
 * 
 * @param instance the `StringBuilder` instance.
 * @param value    the string to append.
 * @return An exception; otherwise `0`.
*/
Exception string_builder_append_string(StringBuilder instance, String value);

/**
 * Appends the string returned by processing a composite format string, which
 * contains zero or more format items, to this instance. Each format item is
 * replaced by the string representation of a corresponding object argument.
 * 
 * @param instance the `StringBuilder` instance.
 * @param format   a composite format string, followed by a variable number of
 *                 template arguments.
 * @return An exception; otherwise, `0`.
*/
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
 * 
 * @param item
 * @param size
 * @return 
*/
size_t string_builder_hash(Object item, size_t size);

/**
 * Determines whether two `StringBuilders` represent the same string value.
 * 
 * @param left  a string builder to compare to `right`. 
 * @param right a string builder to compare to `left`.
 * @return `true` if the two string builders represent the same string values;
 *         otherwise, `false`.
*/
bool string_builder_equals(Object left, Object right);

/**
 * Frees all resources.
 * 
 * @param instance the `StringBuilder` instance. This method corrupts the
 *                 `instance` argument.
*/
void finalize_string_builder(StringBuilder instance);
