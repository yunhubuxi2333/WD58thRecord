#include "queue.h"

#define DEFAULT_CAPACITY 8
#define PREALLOC_MAX 1024

Queue* queue_create() {
	Queue* q = malloc(sizeof(Queue));
	if (!q) {
		printf("Error:malloc failed in vector_create\n");
		exit(1);
	}
	E* p = malloc(DEFAULT_CAPACITY * sizeof(E));
	if (!p) {
		free(q);
		printf("Error:malloc failed in vector_create\n");
		exit(1);
	}
	q->front = 0;
	q->rear = -1;
	q->elements = p;
	q->capacity = DEFAULT_CAPACITY;
	q->size = 0;


	return q;
}

void queue_destroy(Queue* q) {
	//按申请的相反顺序释放
	if (q) {
		free(q->elements);
		free(q);
	}
}

void grow_capacity(Queue* q) {
	int new_capacity = q->capacity < PREALLOC_MAX ? q->capacity << 1 : q->capacity + PREALLOC_MAX;
	//问题是realloc失败会返回NULL,但原来的内存空间不会被释放
	E* p = realloc(q->elements, new_capacity * sizeof(E));
	if (!p) {
		printf("Error:realloc failed in realloc\n");
		exit(1);
	}

	for (int i = 0; i < q->size; i++) {
		p[i] = q->elements[(i + q->front) % q->capacity];
	}

	free(q->elements);
	q->elements = p;
	q->front = 0;
	q->rear = q->size - 1;
	q->capacity = new_capacity;
}

void queue_push(Queue* q, E val) {
	if (q->size == q->capacity) {
		grow_capacity(q);
	}
	q->rear = (q->rear + 1) % q->capacity;
	q->elements[q->rear] = val;
	q->size++;
}

E queue_pop(Queue* q) {
	if (q->size == 0) {
		printf("Error:Queue is empty.\n");
		return -1;
	}
	E front = q->elements[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;

	return front;
}
E queue_peek(Queue* q) {
	if (q->size == 0) {
		printf("Error:Queue is empty.\n");
		return -1;
	}
	return q->elements[q->front];
}

bool queue_empty(Queue* q) {
	return q->size == 0;
}