#include "totient.h"

Exception totient_range(List result, long long max)
{
    /* TODO
    // Exception ex = list_ensure_capacity(result, max);

    // if (ex)
    // {
    //     return ex;
    // }
    */

    for (long long m = 0; m < max; m++)
    {
        Exception ex = list_add(result, m);

        if (ex)
        {
            return ex; // TODO: prevent all these checks by ensuring capacity first
        }
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
