#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

#define container_of(ptr, type, member) \
	(type *)((ptr) - &(((type *)0)->member))

/*
 * To use a single direction list need two base modules
 *
 */

/* 1.List node to add to a list head */
struct list_node {
	int data;
	struct list_node *next;
};

/* 2.List head struct having an list head */
struct list_head {
	struct list_node node;
	int count;
};

void list_init(struct list_head *head)
{
	head->count = 0;
	head->node.next = NULL;
}

int list_empty(struct list_head *head)
{
	return (head->count == 0);
}

struct list_node *list_get_node(struct list_head *head, int index)
{
	struct list_node *pos = &head->node;
	int i = 0;

	if (index >= head->count)
		return NULL;

	while(pos && i++ <= index)
		pos = pos->next;

	/*pos could be NULL*/
	return pos;
}

void list_add(struct list_head *head, struct list_node *node)
{
	struct list_node *pos = &head->node;

	node->next = pos->next;
	pos->next = node;		

	head->count++;
}

void list_add_tail(struct list_head *head, struct list_node *node)
{
	struct list_node *pos = &head->node;

	while(pos->next != NULL) {
		pos = pos->next;
	}
	node->next = NULL;
	pos->next = node;

	head->count++;
}

int list_insert(struct list_head *head, struct list_node *node, int index)
{
	struct list_node *pos;

	pos = list_get_node(head, index - 1);

	if (!pos)
		return -1;
	
	node->next = pos->next;
	pos->next = node;

	head->count++;
	return 0;
}

void list_del(struct list_head *head, struct list_node *node)
{
	struct list_node *pos;

	for (pos = &head->node; pos->next != NULL; pos = pos->next) {
		if (pos->next == node) {
			pos->next = node->next;
			node->next = NULL;
			head->count--;
			break;
		}
	}
}


/***************test sample*****************/
struct list_head head;
int main (int argc, char *argv[])
{
	int i = 0;
	struct list_node *node, *pos;
	
	list_init(&head);

	node = (struct list_node *)malloc(sizeof(struct list_node));
	node->data = 1;
	list_add(&head, node);
	node = (struct list_node *)malloc(sizeof(struct list_node));
	node->data = 2;
	list_insert(&head, node, 2);
	node = (struct list_node *)malloc(sizeof(struct list_node));
	node->data = 3;
	list_add_tail(&head, node);
	pos = node;
	node = (struct list_node *)malloc(sizeof(struct list_node));
	node->data = 4;
	list_add_tail(&head, node);

	for(i = 0, node = head.node.next; node; node = node->next) {
		printf("index[%d]=%d\n", i++, node->data);
	}

	list_del(&head, pos);

	/* TODO: free list node*/

	for(i = 0, node = head.node.next; node; node = node->next) {
		printf("index[%d]=%d\n", i++, node->data);
	}

	/* TODO: free list node*/
	return 0;
}


