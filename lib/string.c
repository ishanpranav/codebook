// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "euler.h"

String string(size_t length)
{
    String result = malloc((length + 1) * sizeof * result);

    if (!result)
    {
        return NULL;
    }

    result[0] = '\0';

    return result;
}

String string_clone(String instance)
{
    String result = malloc((strlen(instance) + 1) * sizeof * result);

    if (!result)
    {
        return NULL;
    }

    return strcpy(result, instance);
}

int string_comparer(const void* left, const void* right)
{
    return strcmp(*(const char**)left, *(const char**)right);
}
