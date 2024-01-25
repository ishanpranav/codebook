#include <math.h>
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

int math_length(int b, int a)
{
    return 1 + (int)(a * log10(b));
}
