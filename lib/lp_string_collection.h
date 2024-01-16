// Licensed under the MIT License.

#include "exception.h"
#include "lp_string.h"
#include "stream.h"

struct LPStringCollection
{
    char** begin;
    char** end;
    size_t capacity;
};

typedef struct LPStringCollection* LPStringCollection;

Exception lp_string_collection(LPStringCollection instance, size_t capacity);
Exception lp_string_collection_add(LPStringCollection instance, LPString item);
void lp_string_collection_sort(LPStringCollection instance);
Exception lp_string_collection_deserialize(
    LPStringCollection instance, 
    Stream input);
void finalize_lp_string_collection(LPStringCollection instance);
