#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree_node TreeNode;
typedef TreeNode* E;

typedef struct {
    E* elements;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// API
Queue* queue_create();
void queue_destroy(Queue* q);

void queue_push(Queue* q, E val);
E queue_pop(Queue* q);
E queue_peek(Queue* q);

bool queue_empty(Queue* q);