// Licensed under the MIT License.

// A Number After a Double Reversal

#include "../lib/euler.h"

bool isSameAfterReversals(int value) 
{
    return math_reverse(math_reverse(value)) == value;
}
