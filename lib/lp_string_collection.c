// Licensed under the MIT License.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "lp_string_builder.h"
#include "lp_string_collection.h"

Exception lp_string_collection(LPStringCollection instance, size_t itemSize, size_t capacity)
{
    if (capacity < 4)
    {
        capacity = 4;
    }

    instance->items = malloc(capacity * itemSize);

    if (!instance->items)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->itemSize = itemSize;
    instance->count = 0;
    instance->capacity = capacity;

    return 0;
}

Exception lp_string_collection_add(LPStringCollection instance, void* value)
{
    if (instance->count + 1 > instance->capacity)
    {
        size_t newCapacity = instance->capacity * 2;
        size_t newSize = newCapacity * instance->itemSize;
        void* newBegin = realloc(instance->items, newSize);

        if (!newBegin)
        {
            return EXCEPTION_OUT_OF_MEMORY;
        }

        instance->capacity = newCapacity;
        instance->items = newBegin;
    }

    memcpy(
        (char*)instance->items + instance->count * instance->itemSize,
        value,
        instance->itemSize);

    instance->count++;

    return 0;
}

void lp_string_collection_sort(LPStringCollection instance)
{
    qsort(
        instance->items,
        instance->count,
        instance->itemSize,
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

    Exception ex = lp_string_collection_add(instance, &value);

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
    free(instance->items);

    instance->items = NULL;
    instance->itemSize = 0;
    instance->count = 0;
    instance->capacity = 0;
}
