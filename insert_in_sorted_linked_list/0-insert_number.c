#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: Double pointer to the head of the list
 * @number: The number to insert
 * Return: The address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *current;

	current = *head;

	new_node = malloc(sizeof(listint_t));
	if(!new_node)
		return (NULL);

	new_node->n = number;

	// Insertion at the beginning of the list or into an empty list
	if (*head == NULL || (*head)->n >= number)
	{
		new_node->next = *head;
		*head = new_node;
	} else {
		// Traversing the list to find the insertion point
		current = *head;

		while (current->next != NULL && current->next->n < number)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
	return (new_node);
}