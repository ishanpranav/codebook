#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"

Exception priority_queue(
    PriorityQueue instance, 
    size_t itemSize,
    size_t prioritySize,
    size_t capacity,
    Comparer priorityComparer)
{
    if (capacity < 4)
    {
        capacity = 4;
    }

    instance->items = malloc(itemSize * capacity);

    if (!instance->items)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->priorities = malloc(prioritySize * capacity);

    if (!instance->priorities)
    {
        free(instance->items);

        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->itemSize = itemSize;
    instance->prioritySize = prioritySize;
    instance->count = 0;
    instance->capacity = capacity;
    instance->priorityComparer = priorityComparer;

    return 0;
}

Exception priority_queue_ensure_capacity(
    PriorityQueue instance, 
    size_t capacity)
{
    if (instance->capacity >= capacity)
    {
        return 0;
    }

    size_t newCapacity = instance->capacity * 2;

    if (capacity > newCapacity)
    {
        newCapacity = capacity;
    }

    void* newItems = realloc(instance->items, newCapacity * instance->itemSize);

    if (!newItems)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    void* newPriorities = realloc(
        instance->priorities, 
        newCapacity * instance->prioritySize);

    if (!newPriorities)
    {
        instance->items = realloc(
            instance->items, 
            instance->capacity * instance->itemSize);

        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->capacity = newCapacity;
    instance->items = newItems;
    instance->priorities = newPriorities;

    return 0;
}

Exception priority_queue_enqueue(
    PriorityQueue instance, 
    Object item, 
    Object priority)
{
    Exception ex = priority_queue_ensure_capacity(
        instance, 
        instance->count + 1);

    if (ex)
    {
        return ex;
    }

    instance->count++;

    char* items = instance->items;
    char* priorities = instance->priorities;
    size_t i = instance->count;
    size_t itemSize = instance->itemSize;
    size_t keySize = instance->prioritySize;
    Comparer compare = instance->priorityComparer;

    while (i != 1 && compare(priority, priorities + i * keySize / 2))
    {
        size_t j = i / 2;

        memcpy(items + i * itemSize, items + j * itemSize, itemSize);
        memcpy(priorities + i * keySize, priorities + j * keySize, keySize);

        i = j;
    }

    memcpy(items + i * itemSize, item, instance->itemSize);
    memcpy(priorities + i * keySize, priority, instance->prioritySize);

    return 0;
}

void finalize_priority_queue(PriorityQueue instance)
{
    free(instance->items);
    free(instance->priorities);

    instance->items = NULL;
    instance->itemSize = 0;
    instance->priorities = NULL;
    instance->prioritySize = 0;
    instance->count = 0;
    instance->capacity = 0;
    instance->priorityComparer = NULL;
}
