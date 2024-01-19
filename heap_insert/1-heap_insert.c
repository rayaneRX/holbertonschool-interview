#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    parent = find_insert_parent(*root);

    new_node->parent = parent;
    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    heapify_up(new_node);

    return (new_node);
}

/**
 * find_insert_parent - Finds the parent for the new node during insertion.
 * @root: Pointer to the root node of the Heap.
 *
 * Return: Pointer to the parent node.
 */
heap_t *find_insert_parent(heap_t *root)
{
    int binary_index;
    heap_t *parent = NULL;

    for (binary_index = 1; root; binary_index <<= 1)
    {
        parent = root;

        if ((binary_index & 1) == 0)
            root = root->left;
        else
            root = root->right;
    }

    return (parent);
}

/**
 * heapify_up - Maintains the Max Heap property by moving the new node up.
 * @node: Pointer to the newly inserted node.
 */
void heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(&(node->n), &(node->parent->n));
        node = node->parent;
    }
}

/**
 * swap_values - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_values(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
