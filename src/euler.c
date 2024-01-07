// Licensed under the MIT License.

#include <stdio.h>
#include "euler.h"

void euler_submit(int id, long long result, clock_t start)
{
    printf("%04d\t%lld\t%lf\n", 
        id, 
        result,
        (double)(clock() - start) / CLOCKS_PER_SEC);
}
