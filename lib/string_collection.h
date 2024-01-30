// Licensed under the MIT License.

#include "list.h"
#include "string.h"
#include "stream.h"

/**
 * Deserializes a collection of strings from a formatted input stream. The
 * caller is responsible for the generated strings.
 * 
 * @param instance the `List` instance.
 * @param input    the input stream.
 * @return The exception; otherwise, `0`.
*/
Exception string_collection_deserialize(List instance, Stream input);
