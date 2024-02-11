// Licensed under the MIT License.

/** Represents an entry in a hash set. */
struct HashSetEntry
{
    void* item;
    struct HashSetEntry* next;
};

/** Represents an entry in a hash set. */
typedef struct HashSetEntry* HashSetEntry;
