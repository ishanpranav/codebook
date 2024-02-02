// Licensed under the MIT License.

// Unique Paths

#include "../lib/binomial.h"

int uniquePaths(int m, int n) 
{
    return binomial(m + n - 2, n - 1);    
}
