#include <math.h>
#include "euler.h"

bool math_is_polygonal(int s, long x)
{
    double term = sqrt(8 * (s - 2) * x + (s - 4) * (s - 4)) + (s - 4);

    term /= 2 * (s - 2);

    return term == (long)term;
}

int math_length(int b, int a)
{
    return 1 + (int)(a * log10(b));
}
