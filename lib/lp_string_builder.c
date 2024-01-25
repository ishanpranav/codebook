// Licensed under the MIT License.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "lp_string_builder.h"

Exception lp_string_builder(LPStringBuilder instance, size_t capacity)
{
    if (capacity < 4)
    {
        capacity = 4;
    }

    instance->begin = malloc(capacity * sizeof * instance->begin);

    if (!instance->begin)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->end = instance->begin;
    instance->capacity = capacity;

    return 0;
}

Exception lp_string_builder_append_char(LPStringBuilder instance, char value)
{
    size_t length = instance->end - instance->begin;

    if (length + 1 > instance->capacity)
    {
        char* newBegin;
        size_t newCapacity = instance->capacity * 2;
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

    *instance->end = value;
    instance->end++;

    return 0;
}

void lp_string_builder_clear(LPStringBuilder instance)
{
    instance->end = instance->begin;
}

LPString lp_string_builder_to_string(LPStringBuilder instance)
{
    size_t length = instance->end - instance->begin;
    LPString result = malloc((length + 1) * sizeof * result);

    if (!result)
    {
        return NULL;
    }

    memcpy(result, instance->begin, length);

    result[length] = '\0';

    return result;
}

bool lp_string_builder_equals(LPStringBuilder left, LPStringBuilder right)
{
    size_t length = left->end - left->begin;

    if ((size_t)(right->end - right->begin) != length)
    {
        return false;
    }

    return memcmp(left->begin, right->begin, length) == 0;
}

size_t lp_string_builder_get_hash_code(LPStringBuilder instance)
{
    size_t result = 5381;
    
    for (char* it = instance->begin; it < instance->end; it++)
    {
        result = (result << 5) + result + *it;
    }

    return result;
}

void finalize_lp_string_builder(LPStringBuilder instance)
{
    free(instance->begin);

    instance->begin = NULL;
    instance->end = NULL;
    instance->capacity = 0;
}
