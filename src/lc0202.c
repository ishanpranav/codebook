// Licensed under the MIT License.

// Happy Number

#include <stdbool.h>
#include "../lib/square_digit_chain.h"

bool lazy;
struct SquareDigitChain chain;

bool isHappy(int n) 
{
    if (!lazy)
    {
        square_digit_chain(&chain);

        lazy = true;
    }

    return square_digit_chain_get(&chain, n) == 1;
}
