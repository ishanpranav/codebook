// Licensed under the MIT License.

// Coin Sums

#include "../lib/euler.h"

int main(void)
{
    int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    int table[201] = { [0] = 1 };
    clock_t start = clock();

    for (int i = 0; i < 8; i++)
    {
        for (int j = coins[i]; j <= 200; j++)
        {
            table[j] += table[j - coins[i]];
        }
    }

    return euler_submit(31, table[200], start);
}
