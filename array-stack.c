/*array stack */
//数组堆栈
#include <stdio.h>

#define STACK_SIZE 20
struct stack {
	int array[STACK_SIZE];
	int sp;  /* top point of stack */
};


int stack_init(struct stack *s)
{
	s->sp = -1;
}


int stack_empty(struct stack *s)
{
	return (s->sp == -1);
}

int stack_full(struct stack *s)
{
	return (s->sp == STACK_SIZE - 1);
}

int push(struct stack *s, int value)
{
	if (stack_full(s))
		return -1;

	s->array[s->sp + 1] = value;
	s->sp++;
	return 0;
}

int pop(struct stack *s)
{
	if (stack_empty(s))
		return -1;

	return s->array[s->sp--];
}

/*************test sample***************/

struct stack stack;

int main (int argc, char *argv[])
{
	struct stack *s = &stack;
	stack_init(s);

	push(s, 1);	
	printf("push 1!\n");

	push(s, 2);
	printf("push 2!\n");
	
	push(s, 3);
	printf("push 3!\n");

	push(s, 4);
	printf("push 4!\n");

	printf("pop:%d\n", pop(s));
	printf("pop:%d\n", pop(s));
	printf("pop:%d\n", pop(s));
	printf("pop:%d\n", pop(s));

	return 0;
}
