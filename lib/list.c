#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

Exception list(List instance, size_t capacity)
{
    instance->begin = malloc(capacity * sizeof * instance->begin);
    
    if (!instance->begin)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }
    
    instance->end = instance->begin;
    instance->capacity = capacity;

    return 0;
}

void list_from_array(List instance, long values[], size_t length)
{
    instance->begin = values;
    instance->end = values + length;
    instance->capacity = length;
}

Exception list_add(List instance, long item)
{
    if (instance->end == instance->begin + instance->capacity)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    *instance->end = item;
    instance->end++;

    return 0;
}

void finalize_list(List instance)
{
    free(instance->begin);

    instance->begin = NULL;
    instance->end = NULL;
    instance->capacity = 0;
}
