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

bool string_starts_with(String instance, String value)
{
    return strncmp(instance, value, strlen(value)) == 0;
}

String string_clone(String instance)
{
    size_t size = strlen(instance) + 1;
    String result = malloc(size * sizeof * result);

    if (!result)
    {
        return NULL;
    }

    return memcpy(result, instance, size);
}

int string_comparer(const void* left, const void* right)
{
    return strcmp(*(const char**)left, *(const char**)right);
}
