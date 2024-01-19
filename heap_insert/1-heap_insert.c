#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap_btree_nodes - Swaps two binary tree nodes
 *
 * @node1: Pointer to first node
 * @node2: Pointer to second node
 */
void swap_btree_nodes(heap_t *node1, heap_t *node2)
{
	int tmp = node1->n;

	node1->n = node2->n;
	node2->n = tmp;
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
		size++;
	}
	return (size);
}

/**
 * find_binary_node_by_index - Finds a binary tree node by index
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @index: Index of the node to find
 * @size: Size of the tree
 *
 * Return: Pointer to the node, or NULL if not found
 */
binary_tree_t *find_binary_node_by_index(binary_tree_t *tree, size_t index,
	size_t size)
{
		heap_t *left;
		heap_t *right;

		if (index > size)
			return (NULL);
		if (index == size)
			return (tree);
		left = find_binary_node_by_index(tree->left, 2 * index + 1, size);
		right = find_binary_node_by_index(tree->right, 2 * index + 2, size);

		return (left ? left : right);
}
/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
		heap_t *new_node;
		heap_t *parent;
		size_t size;

		if (!root)
			return (NULL);
		size = binary_tree_size(*root);
		new_node = binary_tree_node(*root, value);
		if (!new_node)
			return (NULL);
		if (!*root)
		{
			*root = new_node;
			return (new_node);
		}
		parent = find_binary_node_by_index(*root, 0, (size - 1) / 2);
		new_node->parent = parent;
		if (!parent->left)
			parent->left = new_node;
		else
			parent->right = new_node;
		while (new_node->parent && new_node->n > new_node->parent->n)
		{
			swap_btree_nodes(new_node, new_node->parent);
			new_node = new_node->parent;
		}
		return (new_node);
}
