// Licensed under the MIT License.

#include <stddef.h>
#include "comparer.h"
#include "exception.h"
#include "object.h"

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
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
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
 * @return `EXCEPTION_OUT_OF_MEMORY` if there is not enough memory to complete
 *         the operation; otherwise `0`.
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
 * @return An exception; otherwise `0`. This method always returns `0` if the
 *         current capacity is sufficient.
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
 * @return `true` if the minimal item was dequeued successfully; `false` if
 *         the priority queue was empty.
*/
bool priority_queue_try_dequeue(
    PriorityQueue instance, 
    Object item, 
    Object priority);

/**
 * Removes all elements from the priority queue.
 * 
 * @param instance the `PriorityQueue` instance.
*/
void priority_queue_clear(PriorityQueue instance);

/**
 * Frees all resources.
 *
 * @param instance the `PriorityQueue` instance. This method corrupts the
 *                 `instance` argument.
*/
void finalize_priority_queue(PriorityQueue instance);
