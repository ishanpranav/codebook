#include <math.h>
#include <stdbool.h>
#include "boolean_set.h"
#include "prime_list.h"

Exception prime_list(List list, long max)
{
    struct BooleanSet composites;
    Exception ex = boolean_set(&composites, max - 2);

    if (ex)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    double sqrtMax = sqrt(max);

    for (long m = 2; m <= sqrtMax; m++)
    {
        if (composites.begin[m - 2])
        {
            continue;
        }

        for (long n = m * m; n < max; n += m)
        {
            composites.begin[n - 2] = true;
        }
    }

    for (long i = 0; i < max - 2; i++)
    {
        if (composites.begin[i])
        {
            continue;
        }
        
        ex = list_add(list, i + 2);

        if (ex)
        {
            goto free;
        }
    }

free:
    finalize_boolean_set(&composites);

    return ex;
}
