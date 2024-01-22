// Licensed under the MIT License.

#include <stdbool.h>
#include <stddef.h>
#include "exception.h"

/** Represents a set of boolean values. */
struct BooleanSet
{
    bool* begin;
    bool* end;
};

/** Represents a set of boolean values. */
typedef struct BooleanSet* BooleanSet;

/**
 * Initializes a `BooleanSet` instance.
 *
 * @param instance the `BooleanSet` instance.
 * @param capacity the capacity.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception boolean_set(BooleanSet instance, size_t capacity);

/**
 * Intializes a `BooleanSet` instance. Do not call `finalize_boolean_set`.
 *
 * @param instance the `BooleanSet` instance.
 * @param values   the backing array for the set. The caller is responsible for
 *                 this argument.
 * @param length   the length of the `values` argument.
*/
void boolean_set_from_array(BooleanSet instance, bool values[], size_t length);

Exception boolean_set_ensure_capacity(BooleanSet instance, size_t capacity);

/**
 * Frees all resources.
 *
 * @param instance the `BooleanSet` instance. This method corrupts the
 *                 `instance` argument.
*/
void finalize_boolean_set(BooleanSet instance);
