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

    instance->end = instance->begin + capacity;

    return 0;
}

void boolean_set_from_array(BooleanSet instance, bool values[], size_t length)
{
    instance->begin = values;
    instance->end = values + length;
}

void finalize_boolean_set(BooleanSet instance)
{
    free(instance->begin);

    instance->begin = NULL;
}
