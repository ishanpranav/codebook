// Licensed under the MIT License.

#include <math.h>
#include <stdio.h>
#include "euler.h"

Exception euler_submit(int id, long long result, clock_t start)
{
    double elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;
    
    printf("%04d%64lld    %.6lf\n", id, result, elapsed);

    return 0;
}
