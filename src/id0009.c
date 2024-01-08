// Licensed under the MIT License.

// Special Pythagorean Triplet

#include <math.h>
#include "lib/euler.h"

long math_pythagorean_triplet_product(int sum)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int m = 0;
    int n = 0;
    int halfSum = sum / 2;
    int sqrtHalfSum = sqrt(halfSum);

    for (int i = sqrtHalfSum; i <= halfSum; i++)
    {
        if (halfSum % i != 0)
        {
            continue;
        }

        m = halfSum / i;
        n = i - m;
        a = m * m - n * n;
        b = 2 * m * n;
        c = m * m + n * n;

        if (a + b + c == sum)
        {
            break;
        }
    }

    return a * b * (m * m + n * n);
}

int main(void)
{
    clock_t start = clock();
    long product = math_pythagorean_triplet_product(1000);

    euler_submit(9, product, start);

    return 0;
}
