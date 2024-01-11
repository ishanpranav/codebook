// Licensed under the MIT License.

/** Represents text as a zero-terminated sequence of characters. */
typedef char* LPString;

typedef const void* Object;

LPString lp_string_clone(LPString instance);

int lp_string_compare(Object left, Object right);
