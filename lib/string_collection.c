// Licensed under the MIT License.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "string_builder.h"
#include "string_collection.h"

static Exception string_collection_realize(
    List instance,
    StringBuilder builder)
{
    if (builder->length == 0)
    {
        return 0;
    }

    String value = string_builder_to_string(builder);

    if (!value)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    Exception ex = list_add(instance, &value);

    if (ex)
    {
        return ex;
    }

    string_builder_clear(builder);

    return 0;
}

Exception string_collection_deserialize(List instance, Stream input)
{
    struct StringBuilder builder;

    Exception ex = string_builder(&builder, 0);

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
                ex = string_collection_realize(instance, &builder);

                if (ex)
                {
                    finalize_string_builder(&builder);

                    return ex;
                }
                break;

            default:
                ex = string_builder_append_char(&builder, read);

                if (ex)
                {
                    finalize_string_builder(&builder);

                    return ex;
                }
                break;
        }
    }

    ex = string_collection_realize(instance, &builder);

    finalize_string_builder(&builder);

    return ex;
}
