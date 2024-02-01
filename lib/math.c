// Licensed under the MIT License.

#include <math.h>
#include <stdarg.h>
#include "euler.h"

long math_natural_sum(long n)
{
    return n * (n + 1) / 2;
}

long long math_reverse(long long n)
{
    long long x = 0;

    for (long long y = n; y; y /= 10)
    {
        x = (x * 10) + y % 10;
    }

    return x;
}

bool math_is_palindrome(long long n)
{
    return n == math_reverse(n);
}

bool math_is_polygonal(int s, long x, long* approxN)
{
    double sM2 = s - 2;
    double sM4 = sM2 - 2;
    double n = (sqrt(8 * sM2 * x + sM4 * sM4) + sM4) / (2 * sM2);
    long localApproxN = n;

    if (approxN)
    {
        *approxN = localApproxN;
    }

    return n == localApproxN;
}

long long math_length(long long b, long long a)
{
    return 1 + a * log10(b);
}

unsigned long long math_concat_impl(int left, int right, ...)
{
    unsigned long long result = left;
    va_list argl;

    for (va_start(argl, right); right; right = va_arg(argl, int))
    {
        result = result * pow(10, math_length(right, 1)) + right;
    }

    va_end(argl);

    return result;
}
