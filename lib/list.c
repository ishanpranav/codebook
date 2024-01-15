// Licensed under the MIT License.

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
    size_t length = instance->end - instance->begin;

    if (length + 1 > instance->capacity)
    {
        long* newBegin;
        size_t newCapacity;

        if (instance->capacity == 0)
        {
            newCapacity = 4;
        }
        else
        {
            newCapacity = instance->capacity * 2;
        }

        size_t newSize = newCapacity * sizeof * newBegin;

        newBegin = realloc(instance->begin, newSize);

        if (!newBegin)
        {
            return EXCEPTION_OUT_OF_MEMORY;
        }

        instance->capacity = newCapacity;
        instance->begin = newBegin;
        instance->end = newBegin + length;
    }

    *instance->end = item;
    instance->end++;

    return 0;
}

bool list_contains(List instance, long item)
{
    for (long* it = instance->begin; it < instance->end; it++)
    {
        if (*it == item)
        {
            return true;
        }
    }

    return false;
}

void list_clear(List instance)
{
    instance->end = instance->begin;
}

void finalize_list(List instance)
{
    free(instance->begin);

    instance->begin = NULL;
    instance->end = NULL;
    instance->capacity = 0;
}
