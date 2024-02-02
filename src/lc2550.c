// Licensed under the MIT License.

// Monkey Move

#include "../lib/pow.h"

int monkeyMove(int n) 
{
    return (mod_pow(2, n, 1000000007l) - 2 + 1000000007l) % 1000000007l;
}
