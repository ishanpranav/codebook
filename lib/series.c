// Licensed under the MIT License.

#include <ctype.h>
#include "series.h"

void series_from_string(Series instance, String value)
{
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
