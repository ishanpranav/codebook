// Licensed under the MIT License.

/** Represents an entry in a multimap. */
struct LookupEntry
{
    void* key;
    void* value;
    struct LookupEntry* next;
};

/** Represents an entry in a multimap. */
typedef struct LookupEntry* LookupEntry;
