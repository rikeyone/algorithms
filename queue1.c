//1.array queue
//2.list queue
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

struct queue {
	unsigned int array[QUEUE_SIZE];
	int count;
};

void queue_init(struct queue *q)
{
	q->count = 0;
}

int queue_empty(struct queue *q)
{
	return (q->count == 0);
}

int queue_full(struct queue *q)
{
	return (q->count == QUEUE_SIZE);
}

int enqueue(struct queue *q, int value)
{
	if (queue_full(q))
		return -1;

	q->array[q->count++] = value;
	return 0;
}

int dequeue(struct queue *q)
{
	if (queue_empty(q))
		return -1;

	return q->array[--q->count];
}

/**************test sample*******************/

int main(int argc, char *argv[])
{
	struct queue queue;
	queue_init(&queue);
	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);
	enqueue(&queue, 5);

	printf("dequeue:%d\n", dequeue(&queue));
	printf("dequeue:%d\n", dequeue(&queue));
	printf("dequeue:%d\n", dequeue(&queue));
	printf("dequeue:%d\n", dequeue(&queue));
	printf("dequeue:%d\n", dequeue(&queue));
	printf("dequeue:%d\n", dequeue(&queue));
	return 0;
}
