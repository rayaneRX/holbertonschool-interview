#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 if function fails
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    /* Find the last node in level-order */
    last_node = find_last_node(*root);
    if (last_node->parent)
    {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }

    /* Replace root with last node */
    last_node->left = (*root)->left;
    last_node->right = (*root)->right;
    last_node->parent = NULL;
    if (last_node->left)
        last_node->left->parent = last_node;
    if (last_node->right)
        last_node->right->parent = last_node;

    free(*root);
    *root = last_node;

    /* Rebuild the heap */
    heapify_down(*root);

    return (value);
}

/**
 * find_last_node - Finds the last node in a binary tree in level-order
 * @root: Pointer to the root node of the tree
 *
 * Return: Pointer to the last node
 */
heap_t *find_last_node(heap_t *root)
{
    heap_t *last = NULL;
    queue_t *queue = create_queue();
    enqueue(queue, root);

    while (!is_empty(queue))
    {
        last = dequeue(queue);
        if (last->left)
            enqueue(queue, last->left);
        if (last->right)
            enqueue(queue, last->right);
    }

    free_queue(queue);
    return (last);
}

/**
 * heapify_down - Maintains the Max Heap property by performing heapify down
 * @node: Pointer to the node to heapify down
 */
void heapify_down(heap_t *node)
{
    int temp;
    heap_t *largest = node;

    while (1)
    {
        if (node->left && node->left->n > largest->n)
            largest = node->left;
        if (node->right && node->right->n > largest->n)
            largest = node->right;
        if (largest == node)
            break;

        temp = node->n;
        node->n = largest->n;
        largest->n = temp;

        node = largest;
    }
}

/**
 * create_queue - Creates a queue
 *
 * Return: Pointer to the created queue
 */
queue_t *create_queue(void)
{
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
        return (NULL);
    queue->front = NULL;
    queue->rear = NULL;
    return (queue);
}

/**
 * is_empty - Checks if the queue is empty
 * @queue: Pointer to the queue
 *
 * Return: 1 if the queue is empty, 0 otherwise
 */
int is_empty(queue_t *queue)
{
    return (queue->front == NULL);
}

/**
 * enqueue - Adds an element to the queue
 * @queue: Pointer to the queue
 * @node: Pointer to the node to add to the queue
 */
void enqueue(queue_t *queue, heap_t *node)
{
    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (!new_node)
        return;
    new_node->node = node;
    new_node->next = NULL;
    if (is_empty(queue))
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

/**
 * dequeue - Removes an element from the queue
 * @queue: Pointer to the queue
 *
 * Return: Pointer to the removed node
 */
heap_t *dequeue(queue_t *queue)
{
    queue_node_t *temp;
    heap_t *node;

    if (is_empty(queue))
        return (NULL);

    temp = queue->front;
    node = temp->node;
    queue->front = queue->front->next;
    if (!queue->front)
        queue->rear = NULL;

    free(temp);
    return (node);
}

/**
 * free_queue - Frees the memory allocated for the queue
 * @queue: Pointer to the queue
 */
void free_queue(queue_t *queue)
{
    while (!is_empty(queue))
        dequeue(queue);
    free(queue);
}
