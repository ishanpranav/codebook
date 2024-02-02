// Licensed under the MIT License.

// Palindrome Number

#include "../lib/euler.h"

bool isPalindrome(int value)
{
    return value >= 0 && math_is_palindrome(value);
}
