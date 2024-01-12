// Licensed under the MIT License.

#include <ctype.h>
#include <stdlib.h>
#include "series.h"

Series series_from_string(LPString value)
{
    Series instance = malloc(sizeof * instance);

    if (!instance)
    {
        return NULL;
    }

    char* end = value;

    for (char* p = value; *p; p++)
    {
        if (isdigit(*p))
        {
            *end = *p - '0';
            end++;
        }
    }

    instance->begin = value;
    instance->end = end;

    return instance;
}

int series_sum(Series instance)
{
    int result = 0;
    
    for (char* it = instance->begin; it < instance->end; it++)
    {
        result += *it;
    }

    return result;
}
