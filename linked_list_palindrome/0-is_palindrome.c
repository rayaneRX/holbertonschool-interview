#include "lists.h"

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to pointer of the first node of list
 *
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to pointer of the first node of list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return 1;

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev_slow = *head;
    listint_t *mid = NULL;
    listint_t *second_half = NULL;
    int palindrome = 1;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    if (fast != NULL)
    {
        mid = slow;
        slow = slow->next;
    }

    second_half = slow;
    prev_slow->next = NULL;

    reverse_list(&second_half);

    listint_t *list1 = *head;
    listint_t *list2 = second_half;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->n != list2->n)
        {
            palindrome = 0;
            break;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    reverse_list(&second_half);

    if (mid != NULL)
    {
        prev_slow->next = mid;
        mid->next = second_half;
    }
    else
    {
        prev_slow->next = second_half;
    }

    return palindrome;
}
