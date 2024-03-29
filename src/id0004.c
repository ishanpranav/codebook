// Licensed under the MIT License.

// Largest Palindrome Product

#include "../lib/euler.h"

int main(void)
{
    long max = 0;
    clock_t start = clock();

    for (int a = 999; a >= 100; a--)
    {
        int b;
        int db;

        if (a % 11 == 0)
        {
            b = 999;
            db = -1;
        }
        else
        {
            b = 990;
            db = -11;
        }

        while (b >= a)
        {
            long product = a * b;

            if (product <= max)
            {
                break;
            }

            if (math_is_palindrome(product))
            {
                max = product;
            }

            b += db;
        }
    }

    return euler_submit(4, max, start);
}
