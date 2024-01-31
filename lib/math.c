// Licensed under the MIT License.

#include <math.h>
#include <stdarg.h>
#include "euler.h"

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
