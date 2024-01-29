// Licensed under the MIT License.

// Combinatoric Selections

#include "../lib/binomial.h"
#include "../lib/euler.h"

int main(void)
{
    int count = 0;
    clock_t start = clock();

    for (int n = 1; n <= 100; n++)
    {
        bool last = false;

        for (int r = 1; r <= n / 2; r++)
        {
            long long c = binomial(n, r);

            last = c > 1000000l || c < 0;

            if (last)
            {
                count += 2;
            }
        }

        if (n % 2 == 1 && last)
        {
            count--;
        }
    }

    return euler_submit(53, count, start);
}
