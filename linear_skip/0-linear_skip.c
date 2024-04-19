#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located,
 *         or NULL if value is not present in list or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current, *prev;

    if (list == NULL)
        return NULL;

    current = list;
    while (current != NULL)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->n == value)
            return current;
        if (current->express == NULL || current->express->n > value)
        {
            prev = current;
            printf("Value found between indexes [%lu] and [%lu]\n",
                   prev->index, current->express != NULL ? current->express->index : 0);
            while (prev != NULL && prev->index <= (current->express != NULL ? current->express->index : 0))
            {
                printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
                if (prev->n == value)
                    return prev;
                prev = prev->next;
            }
            return NULL;
        }
        current = current->express;
    }
    return NULL;
}
