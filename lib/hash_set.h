#include <stdbool.h>
#include "equality_comparer.h"
#include "exception.h"
#include "hash.h"

struct HashSetEntry
{
    void* item;
    struct HashSetEntry* next;
};

struct HashSet
{
    size_t (*itemHash)(void* item, size_t size);
    bool (*itemEqualityComparer)(void* left, void* right);

    struct HashSetEntry** entries;
    size_t itemSize;
    size_t count;
    size_t capacity;
    size_t maxChainLength;
    double minLoadFactor;
};

typedef struct HashSet* HashSet;
typedef struct HashSetEntry* HashSetEntry;

Exception hash_set(
    HashSet instance,
    size_t itemSize,
    size_t capacity,
    EqualityComparer itemEqualityComparer,
    Hash itemHash);

Exception hash_set_add(HashSet instance, Object item, bool* added);

bool hash_set_contains(HashSet instance, Object item);

void hash_set_clear(HashSet instance);

void finalize_hash_set(HashSet instance);
