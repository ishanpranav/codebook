// Licensed under the MIT License.

#include "totient.h"

Exception totient_range(List result, long long max)
{
    Exception ex = list_ensure_capacity(result, max);

    if (ex)
    {
        return ex;
    }
    
    for (long long m = 0; m < max; m++)
    {
        list_add(result, m);
    }

    for (long long m = 2; m < max; m++)
    {
        if (result->begin[m] == m)
        {
            result->begin[m] = m - 1;

            for (long long n = m + m; n < max; n += m)
            {
                result->begin[n] -= result->begin[n] / m;
            }
        }
    }

    return 0;
}
