// Licensed under the MIT License.

// Special Pythagorean Triplet

#include <math.h>
#include "../lib/euler.h"

int main(void)
{
    clock_t start = clock();    
    int a = 0;
    int b = 0;
    int c = 0;
    int m = 0;
    int n = 0;
    int sqrtHalfSum = sqrt(500);

    for (int i = sqrtHalfSum; i <= 500; i++)
    {
        if (500 % i != 0)
        {
            continue;
        }

        m = 500 / i;
        n = i - m;
        a = m * m - n * n;
        b = 2 * m * n;
        c = m * m + n * n;

        if (a + b + c == 1000)
        {
            break;
        }
    }

    long product = a * b * (m * m + n * n);
    
    return euler_submit(9, product, start);
}
