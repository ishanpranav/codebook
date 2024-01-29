// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "lp_string.h"

LPString lp_string(size_t length)
{
    LPString result = malloc((length + 1) * sizeof * result);

    if (result == NULL)
    {
        return NULL;
    }

    result[0] = '\0';

    return result;
}

LPString lp_string_clone(LPString instance)
{
    LPString result = malloc((strlen(instance) + 1) * sizeof * result);

    if (!result)
    {
        return NULL;
    }

    return strcpy(result, instance);
}

int lp_string_compare(const void* left, const void* right)
{
    return strcmp(*(const char**)left, *(const char**)right);
}
