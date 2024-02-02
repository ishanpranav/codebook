// Licensed under the MIT License.

// Divide Two Integers

#include <limits.h>

int divide(int dividend, int divisor) 
{
    long long quotient = (long long)dividend / divisor;

    if (quotient > INT_MAX)
    {
        return INT_MAX;
    }
    
    if (quotient < INT_MIN) 
    {
        return INT_MIN;
    }
    
    return quotient;
}
