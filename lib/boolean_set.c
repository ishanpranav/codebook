// Licensed under the MIT License.

#include <stdlib.h>
#include "boolean_set.h"

Exception boolean_set(BooleanSet instance, size_t capacity)
{
    instance->begin = calloc(capacity, sizeof * instance->begin);

    if (!instance->begin)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    return 0;
}

void finalize_boolean_set(BooleanSet instance)
{
    free(instance->begin);

    instance->begin = NULL;
}
