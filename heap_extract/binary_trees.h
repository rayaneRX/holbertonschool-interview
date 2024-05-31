#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Basic Binary Tree structure */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/* Function prototypes */
int heap_extract(heap_t **root);
heap_t *find_last_node(heap_t *root);
void heapify_down(heap_t *node);
heap_t *_array_to_heap(int *array, size_t size);
void _binary_tree_delete(binary_tree_t *tree);

void insert_node(heap_t *root, heap_t *node); // Add this prototype
void heapify_up(heap_t *node); // Add this prototype

/* Queue structure and function prototypes for level-order traversal */
typedef struct queue_node_s
{
    heap_t *node;
    struct queue_node_s *next;
} queue_node_t;

typedef struct queue_s
{
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;

queue_t *create_queue(void);
int is_empty(queue_t *queue);
void enqueue(queue_t *queue, heap_t *node);
heap_t *dequeue(queue_t *queue);
void free_queue(queue_t *queue);

#endif /* BINARY_TREES_H */
