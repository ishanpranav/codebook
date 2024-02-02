// Licensed under the MIT License.

// Find the Index of the First Occurrence in a String

#include <string.h>
#include "../lib/euler.h"

int strStr(String value, String substring) 
{
    char* p = strstr(value, substring);

    if (!p)
    {
        return -1;
    }

    return p - value;
}
