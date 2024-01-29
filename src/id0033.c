// Licensed under the MIT License.

// Digit Cancelling Fractions

#include "../lib/euclidean.h"
#include "../lib/euler.h"

int main(void)
{
    long x = 1;
    long y = 1;
    clock_t start = clock();

    for (int a2 = 1; a2 <= 9; a2++)
    {
        for (int a1 = 1; a1 < a2; a1++)
        {
            for (int b2 = 1; b2 < 9; b2++)
            {
                int a = 10 * a1 + a2;
                int b = 10 * a2 + b2;

                if (a * b2 == b * a1)
                {
                    x *= a;
                    y *= b;
                }
            }
        }
    }

    y /= gcd(x, y);
 
    return euler_submit(33, y, start);
}
