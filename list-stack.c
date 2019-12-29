/* list based stack */
//链表堆栈

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct stack_node {
	void *data;
	struct stack_node *next;
};

struct stack {
	struct stack_node *sp;
	struct stack_node head;
};


void stack_init(struct stack *s)
{
	s->sp = &s->head;
	s->sp->next = NULL;
}

int stack_empty(struct stack *s)
{
	return	(s->sp->next == NULL);
}

int push(struct stack *s, void *data)
{
	struct stack_node *node;

	node = (struct stack_node *)malloc(sizeof(struct stack_node));
	if (!node) {
		printf("malloc error:%s\n", strerror(errno));
		return -1;
	}
	node->data = data;
	node->next = s->sp->next;
	s->sp->next = node;

	return 0;
}

void *pop(struct stack *s)
{
	struct stack_node *node;
	void *data;

	if (stack_empty(s))
		return NULL;

	node = s->sp->next;
	s->sp->next = node->next;
	data = node->data;

	free(node);
	return data;
}


/*************test sample**********************/

int main(int argc, char *argv[])
{
	struct stack stack;
	struct stack_node *node;
	int push_val1 = 1;
	int push_val2 = 2;
	int push_val3 = 3;
	int *pop_val;

	stack_init(&stack);
	push(&stack, &push_val1);
	push(&stack, &push_val2);
	push(&stack, &push_val3);

	pop_val = (int *)pop(&stack);
	if (pop_val)
		printf("pop 1:%d\n", *pop_val);
	pop_val = (int *)pop(&stack);
	if (pop_val)
		printf("pop 2:%d\n", *pop_val);
	pop_val = (int *)pop(&stack);
	if (pop_val)
		printf("pop 3:%d\n", *pop_val);

	return 0;
}
