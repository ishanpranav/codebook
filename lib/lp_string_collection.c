// Licensed under the MIT License.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "lp_string_builder.h"
#include "lp_string_collection.h"

Exception lp_string_builder(LPStringBuilder instance, size_t capacity)
{
    if (!capacity)
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

void finalize_lp_string_builder(LPStringBuilder instance)
{
    free(instance->begin);

    instance->begin = NULL;
    instance->end = NULL;
    instance->capacity = 0;
}

Exception lp_string_collection(LPStringCollection instance, size_t capacity)
{
    if (!capacity)
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

Exception lp_string_collection_add(LPStringCollection instance, LPString value)
{
    size_t length = instance->end - instance->begin;

    if (length + 1 > instance->capacity)
    {
        LPString* newBegin;
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

void lp_string_collection_sort(LPStringCollection instance)
{
    qsort(
        instance->begin,
        instance->end - instance->begin,
        sizeof * instance->begin,
        lp_string_compare);
}

static Exception lp_string_collection_realize(
    LPStringCollection instance,
    LPStringBuilder builder)
{
    if (builder->end - builder->begin == 0)
    {
        return 0;
    }

    LPString value = lp_string_builder_to_string(builder);

    if (!value)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    Exception ex = lp_string_collection_add(instance, value);

    if (ex)
    {
        return ex;
    }

    lp_string_builder_clear(builder);

    return 0;
}

Exception lp_string_collection_deserialize(
    LPStringCollection instance,
    Stream input)
{
    struct LPStringBuilder builder;

    Exception ex = lp_string_builder(&builder, 0);

    if (ex)
    {
        return ex;
    }

    for (int read = getc(input); read != EOF; read = getc(input))
    {
        switch (read)
        {
            case '"': continue;

            case ',':
                ex = lp_string_collection_realize(instance, &builder);

                if (ex)
                {
                    finalize_lp_string_builder(&builder);

                    return ex;
                }
                break;

            default:
                ex = lp_string_builder_append_char(&builder, read);

                if (ex)
                {
                    finalize_lp_string_builder(&builder);

                    return ex;
                }
                break;
        }
    }

    ex = lp_string_collection_realize(instance, &builder);

    finalize_lp_string_builder(&builder);

    return ex;
}

void finalize_lp_string_collection(LPStringCollection instance)
{
    free(instance->begin);

    instance->begin = NULL;
    instance->end = NULL;
    instance->capacity = 0;
}
