// Licensed under the MIT License.

// Special Pythagorean Triplet

#include <math.h>
#include "../lib/euler.h"

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    clock_t start = clock();

    for (int i = sqrt(500); i <= 500; i++)
    {
        if (500 % i != 0)
        {
            continue;
        }

        int m = 500 / i;
        int n = i - m;
        
        a = m * m - n * n;
        b = 2 * m * n;
        c = m * m + n * n;

        if (a + b + c == 1000)
        {
            break;
        }
    }

    long product = a * b * c;

    return euler_submit(9, product, start);
}
