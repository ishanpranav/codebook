// Licensed under the MIT License.

// Valid Perfect Square

#include "../lib/euler.h"

bool isPerfectSquare(int value) 
{
    return math_is_polygonal(4, value, NULL);
}
