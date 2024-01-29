// Licensed under the MIT License.

#include <stdbool.h>
#include "object.h"

/** */
typedef bool (*EqualityComparer)(Object left, Object right);

/**
 * @param left
 * @param right
*/
bool int_equality_comparer(Object left, Object right);

/**
 * 
 * 
*/
bool long_equality_comparer(Object left, Object right);

/**
 * 
 * 
*/
bool double_equality_comparer(Object left, Object right);
