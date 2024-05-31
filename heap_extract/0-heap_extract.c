#include "binary_trees.h"

/**
 * swap_nodes - Swaps two nodes in a binary heap
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_down - Ensures the heap property is maintained after extraction
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;
	if (largest != root)
	{
		swap_nodes(root, largest);
		heapify_down(largest);
	}
}

/**
 * get_last_node - Finds the last node in level-order traversal
 * @root: Pointer to the root node
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;
	heap_t *last = NULL;

	if (!root)
		return (NULL);

	queue[rear++] = root;
	while (front < rear)
	{
		last = queue[front++];
		if (last->left)
			queue[rear++] = last->left;
		if (last->right)
			queue[rear++] = last->right;
	}

	return (last);
}

/**
 * heap_extract - Extracts the root node of a max binary heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node, *root_node;

	if (!root || !*root)
		return (0);

	root_node = *root;
	value = root_node->n;

	if (!root_node->left && !root_node->right)
	{
		free(root_node);
		*root = NULL;
		return (value);
	}

	last_node = get_last_node(root_node);

	if (last_node == root_node)
	{
		free(root_node);
		*root = NULL;
		return (value);
	}

	root_node->n = last_node->n;
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);
	heapify_down(root_node);

	return (value);
}
