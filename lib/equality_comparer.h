// Licensed under the MIT License.

#include <stdbool.h>
#include "object.h"

/** */
typedef bool (*EqualityComparer)(Object left, Object right);

/**
 * 
 * 
*/
bool int_equality_comparer(Object left, Object right);
