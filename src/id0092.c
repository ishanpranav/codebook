// Licensed under the MIT License.

// Square Digit Chains

#include "../lib/euler.h"
#include "../lib/square_digit_chain.h"

int main(void)
{
    long count = 0;
    struct SquareDigitChain chain;
    clock_t start = clock();

    square_digit_chain(&chain);

    for (long n = 1; n < 10000000l; n++)
    {
        if (square_digit_chain_get(&chain, n) == 89)
        {
            count++;
        }
    }

    return euler_submit(92, count, start);
}
