#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list.
 * @list: A pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where value is located,
 * or NULL if value is not present or list is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    if (!list)
        return NULL;

    skiplist_t *node = list, *express = list->express;

    while (express != NULL && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        node = express;
        express = express->express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           node->index, (express ? express->index : node->index));

    while (node != NULL && node->n <= express->n)
    {
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
        if (node->n == value)
            return node;
        node = node->next;
    }

    return NULL;
}
