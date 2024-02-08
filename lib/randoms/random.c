// Licensed under the MIT License.

#include <stdlib.h>
#include "../random.h"

long long random(Object instance, long long max)
{
    if (max > RAND_MAX)
    {
        max = RAND_MAX;
    }
    
    unsigned int* next = instance;

    *next = *next * 1103515245 + 12345;

    return ((unsigned int)(*next / 65536) % (max + 1));
}
