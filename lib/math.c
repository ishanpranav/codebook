#include <math.h>
#include "euler.h"

bool math_is_polygonal(int s, long x)
{
    double sM2 = s - 2;
    double sM4 = sM2 - 2;
    double term = (sqrt(8 * sM2 * x + sM4 * sM4) + sM4) / (2 * sM2);

    return term == (long)term;
}

int math_length(int b, int a)
{
    return 1 + (int)(a * log10(b));
}
