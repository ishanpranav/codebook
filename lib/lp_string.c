#include <stdlib.h>
#include <string.h>
#include "lp_string.h"

LPString lp_string_clone(LPString instance)
{
    LPString result = malloc((strlen(instance) + 1) * sizeof * result);

    if (!result)
    {
        return NULL;
    }

    return strcpy(result, instance);
}

int lp_string_compare(Object left, Object right)
{
    const char* a = *(const char**)left;
    const char* b = *(const char**)right;

    return strcmp(a, b);
}
