// Licensed under the MIT License.

#include <stddef.h>
#include "object.h"

/** Defines a method that a type implements to hash an object. */
typedef size_t (*Hash)(Object item, size_t size);
