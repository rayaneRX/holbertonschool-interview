#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to the head of the list
 * Return: 1 if there is a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
    listint_t *slow = list, *fast = list;

    while (slow && fast && fast->next)
    {
        slow = slow->next;          /* Move slow pointer by one */
        fast = fast->next->next;    /* Move fast pointer by two */

        /* If slow and fast pointers meet, there is a cycle */
        if (slow == fast)
            return 1;
    }

    /* No cycle found */
    return 0;
}
