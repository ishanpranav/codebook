// Licensed under the MIT License.

// Lychrel Numbers

#include "../lib/euler.h"

static bool math_is_pseudo_lychrel(long long n)
{
    for (int i = 0; i < 50; i++)
    {
        if (n < 0)
        {
            return true;
        }
        
        long long reversed = math_reverse(n);

        n += reversed;

        if (math_is_palindrome(n))
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int count = 0;
    clock_t start = clock();

    for (int i = 0; i < 10000; i++)
    {
        if (math_is_pseudo_lychrel(i))
        {
            count++;
        }
    }

    return euler_submit(55, count, start);
}
