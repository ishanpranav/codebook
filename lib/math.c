#include <math.h>
#include "euler.h"

bool math_is_pentagonal(long n)
{
    double term = (sqrt(24 * n + 1) + 1) / 6;

    return term == (long)term;
}

bool math_is_square(long n)
{
    double sqrtN = sqrt(n);

    return sqrtN == (long)sqrtN;    
}
