#include "binary_trees.h"

/**
 * create_node - creates a new AVL node
 * @value: value to store in the new node
 *
 * Return: pointer to the new node, or NULL on failure
*/
avl_t *create_node(int value)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;

	return (new_node);
}

/**
 * sortedArrayToAVL - builds an AVL tree from a sorted array
 * @array: A pointer to the sorted table.
 * @start: index of the first element in the array
 * @end: index of the last element in the array
 * @parent: parent node of the current node
 *
 * Return: A pointer to the root of the AVL tree.
 */
avl_t *sortedArrayToAVL(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_node(array[mid]);

	if (root == NULL)
		return (NULL);

	root->parent = parent;
	root->left = sortedArrayToAVL(array, start, mid - 1, root);
	root->right = sortedArrayToAVL(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: A pointer to the sorted table.
 * @size: The size of the array.
 *
 * Return: A pointer to the root of the AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sortedArrayToAVL(array, 0, size - 1, NULL));
}
