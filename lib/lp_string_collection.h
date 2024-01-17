// Licensed under the MIT License.

#include "exception.h"
#include "lp_string.h"
#include "stream.h"

/** Represents a collection of strings. */
struct LPStringCollection
{
    char** begin;
    char** end;
    size_t capacity;
};

/** Represents a collection of strings. */
typedef struct LPStringCollection* LPStringCollection;

/**
 * Initializes an `LPStringCollection` instance.
 * 
 * @param instance the `LPStringCollection` instance.
 * @param capacity the required minimum capacity.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception lp_string_collection(LPStringCollection instance, size_t capacity);

/**
 * Adds a string to the end of the collection.
 *
 * @param instance the `LPStringCollection` instance.
 * @param item     the string to add.
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
*/
Exception lp_string_collection_add(LPStringCollection instance, LPString value);

/**
 * Sorts the collection.
 * 
 * @param instance the `LPStringCollection` instance.
*/
void lp_string_collection_sort(LPStringCollection instance);

/**
 * Deserializes a collection of strings from a formatted input stream.
 * 
 * @param instance the `LPStringCollection` instance.
 * @param input    the input stream.
 * @return The exception; otherwise, `0`.
*/
Exception lp_string_collection_deserialize(
    LPStringCollection instance, 
    Stream input);

/**
 * Frees all resources.
 * 
 * @param instance the `LPStringCollection` instance. This method corrupts the
 *                 `instance` argument.
*/
void finalize_lp_string_collection(LPStringCollection instance);
