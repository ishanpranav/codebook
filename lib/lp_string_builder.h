// Licensed under the MIT License.

#include <stddef.h>
#include "exception.h"
#include "lp_string.h"

struct LPStringBuilder
{
    char* begin;
    char* end;
    size_t capacity;
};

typedef struct LPStringBuilder* LPStringBuilder;

Exception lp_string_builder(LPStringBuilder instance, size_t capacity);
Exception lp_string_builder_append_char(LPStringBuilder instance, char item);
void lp_string_builder_clear(LPStringBuilder instance);
LPString lp_string_builder_to_string(LPStringBuilder instance);
