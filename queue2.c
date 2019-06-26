//list queue
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

struct queue_node {
	void *data;
	struct queue_node *prev, *next;
};

struct queue {
	struct queue_node head;
};

void queue_init(struct queue *q)
{
	struct queue_node *head = &q->head;
	head->prev = head;
	head->next = head;
}

int queue_empty(struct queue *q)
{
	struct queue_node *head = &q->head;
	return (head->next == head);
}

int enqueue(struct queue *q, void *data)
{

	struct queue_node *node;
	struct queue_node *prev = &q->head;
	struct queue_node *next = prev->next;

	node = (struct queue_node *)malloc(sizeof(struct queue_node));
	node->data = data;

	node->next = next;
	next->prev = node;
	node->prev = prev;
	prev->next = node;
	return 0;
}

void *dequeue(struct queue *q)
{
	struct queue_node *prev = &q->head;
	struct queue_node *node = prev->next;
	struct queue_node *next = node->next;
	void *data;

	if (queue_empty(q))
		return NULL;

	prev->next = next;
	next->prev = prev;

	node->next = NULL;
	node->prev = NULL;
	data = node->data;
	free(node);

	return data;
}

/**************test sample*******************/

int main(int argc, char *argv[])
{
	struct queue queue;
	int value1 = 1;
	int value2 = 22;
	int value3 = 333;
	int value4 = 4444;

	queue_init(&queue);
	enqueue(&queue, &value1);
	enqueue(&queue, &value2);
	enqueue(&queue, &value3);
	enqueue(&queue, &value4);
	enqueue(&queue, &value1);

	printf("dequeue:%d\n", *((int *)dequeue(&queue)));
	printf("dequeue:%d\n", *((int *)dequeue(&queue)));
	printf("dequeue:%d\n", *((int *)dequeue(&queue)));
	printf("dequeue:%d\n", *((int *)dequeue(&queue)));
	printf("dequeue:%d\n", *((int *)dequeue(&queue)));
	return 0;
}
