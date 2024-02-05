// Licensed under the MIT License.

#include "comparer.h"
#include "exception.h"
#include "priority_queue_element.h"

/**
 * Represents a collection of items that have a value and a priority. On
 * dequeue, the item with the lowest priority value is removed.
*/
struct PriorityQueue
{
    int (*priorityComparer)(const void* left, const void* right);
    
    void* items;
    void* priorities;
    size_t itemSize;
    size_t prioritySize;
    size_t count;
    size_t capacity;
};

/**
 * Represents a collection of items that have a value and a priority. On
 * dequeue, the item with the lowest priority value is removed.
*/
typedef struct PriorityQueue* PriorityQueue;

/**
 * Initializes a `PriorityQueue` instance.
 * 
 * @param instance         the `PriorityQueue` instance.
 * @param itemSize         the size of each item in the queue.
 * @param prioritySize     the size of each priority in the queue.
 * @param capacity         the required minimum capacity.
 * @param priorityComparer the comparer used to order priorities.
*/
Exception priority_queue(
    PriorityQueue instance,
    size_t itemSize,
    size_t prioritySize,
    size_t capacity,
    Comparer priorityComparer);

/**
 * Ensures that the `PriorityQueue` can hold up to a given `capacity` of items
 * without further expansion of its backing storage.
 * 
 * @param instance the `PriorityQueue` instance.
 * @param capacity the required minimum capacity.
*/
Exception priority_queue_ensure_capacity(
    PriorityQueue instance,
    size_t capacity);

/**
 * Adds the specified item with associated priority to the `PriorityQueue`.
 * 
 * @param instance the `PriorityQueue` instance.
 * @param item     the item.
 * @param priority the priority.
*/
Exception priority_queue_enqueue(
    PriorityQueue instance, 
    Object item, 
    Object priority);

/**
 * Removes the minimal item from the `PriorityQueue`, and copies it to the given
 * `item` pointer and its associated priority to the given `priority` poitner.
 * 
 * @param result   when this method returns, contains the minimal item. This
 *                 argument is passed uninitialized, or `NULL` if the value will
 *                 not be used.
 * @param priority when this method returns, contains the minimal priority. This
 *                 argument is passed uninitialized, or `NULL` if the value will
 *                 not be used.
 * @param instance the `PriorityQueue` instance.
*/
bool priority_queue_try_dequeue(
    PriorityQueue instance, 
    Object item, 
    Object priority);

/**
 * Frees all resources.
 *
 * @param instance the `PriorityQueue` instance. This method corrupts the
 *                 `instance` argument.
*/
void finalize_priority_queue(PriorityQueue instance);
