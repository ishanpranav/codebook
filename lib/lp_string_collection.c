// Licensed under the MIT License.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "lp_string_builder.h"
#include "lp_string_collection.h"

static Exception lp_string_collection_realize(
    List instance,
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

    Exception ex = list_add(instance, &value);

    if (ex)
    {
        return ex;
    }

    lp_string_builder_clear(builder);

    return 0;
}

Exception lp_string_collection_deserialize(List instance, Stream input)
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
