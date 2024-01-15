// Licensed under the MIT License.

// Double-base Palindromes

#include "../lib/euler.h"

bool math_is_binary_palindrome(unsigned long n)
{
    unsigned long x = 0;

    for (unsigned long y = n; y; y >>= 1)
    {
        x = (x << 1) | (y & 1);
    }

    return x == n;
}

long math_odd_palindrome(long n)
{
    long result = n;

    for (long k = n / 10; k; k /= 10)
    {
        result = result * 10 + (k % 10);
    }

    return result;
}

long math_even_palindrome(long n)
{
    long result = n;

    for (long k = n; k; k /= 10)
    {
        result = result * 10 + (k % 10);
    }

    return result;
}

int main(void)
{
    long n;
    long sum = 0;
    clock_t start = clock();

    for (long i = 1; (n = math_odd_palindrome(i)) < 1000000l; i++)
    {
        if (math_is_binary_palindrome(n))
        {
            sum += n;
        }
    }

    for (long i = 1; (n = math_even_palindrome(i)) < 1000000l; i++)
    {
        if (math_is_binary_palindrome(n))
        {
            sum += n;
        }
    }
    
    return euler_submit(36, sum, start);
}
