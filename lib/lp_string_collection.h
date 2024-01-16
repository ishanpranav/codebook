// Licensed under the MIT License.

#include <stdio.h>
#include "exception.h"
#include "lp_string.h"

struct LPStringCollection
{
    char** begin;
    char** end;
};

typedef struct LPStringCollection* LPStringCollection;
typedef FILE* Stream;

Exception lp_string_collection(LPStringCollection instance);
Exception lp_string_collection_add(LPStringCollection instance);
void lp_string_collection_sort(LPStringCollection instance);
Exception lp_string_collection_deserialize(
    LPStringCollection instance, 
    Stream input);
void finalize_lp_string_collection(LPStringCollection instance);
