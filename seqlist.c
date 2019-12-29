/*
 * 顺序表
 *
 */


#include <string.h>
#include <stdio.h>

#define MAX_SIZE 50

typedef int seqdata;

struct seqlist {
	seqdata array[MAX_SIZE];
	int count;
};

void seqlist_init(struct seqlist *list)
{
	memset(list->array, 0, sizeof(list->array));
	list->count = 0;
}

int seqlist_add(struct seqlist *list, seqdata value)
{
	if (list->count >= MAX_SIZE)
		return -1;

	list->array[list->count] = value;
	list->count++;
	return 0;
}

int seqlist_insert(struct seqlist *list, int index, seqdata value)
{
	int i, j;

	if (list->count >= MAX_SIZE)
		return -1;

	if (index >= list->count)
		return -1;

	/* move valid data form [index] ~ [list->count -1] */
	for (i = list->count - 1; i >= index; i--) {
		list->array[i + 1] = list->array[i];
	}
	list->array[index] = value;
	list->count++;

	return 0;
}

int seqlist_remove(struct seqlist *list, int index)
{
	int i;

	if (index >= list->count)
		return -1;

	/* move valid data index form [index+1] ~ [list->count -1] */
	for (i = index + 1; i < list->count; i++) {
		list->array[i - 1] = list->array[i];
	}
	list->count--;
	return 0;
}

int seqlist_get_index(struct seqlist *list, seqdata value)
{
	int i;

	for (i = 0; i < list->count; i++) {
		if (list->array[i] == value)
			break;
	}
	if (i >= list->count)
		return -1;

	return i;
}

seqdata seqlist_get_value(struct seqlist *list, int index)
{
	if (index >= list->count)
		return -1;

	return list->array[index];
}

void print_seqlist(struct seqlist *list)
{
	int i;

	printf("Seqlist number:%d\n", list->count);
	for (i = 0; i < list->count; i++)
		printf("Data[%d]:%d, ", i, list->array[i]);
	printf("\n");
}

int main(int argc, char *argv[])
{
	struct seqlist seqlist;
	seqlist_init(&seqlist);
	seqlist_add(&seqlist, 1);
	seqlist_add(&seqlist, 2);
	seqlist_add(&seqlist, 3);
	seqlist_add(&seqlist, 4);
	seqlist_add(&seqlist, 5);
	printf("Init seqlite:\n");
	print_seqlist(&seqlist);
	printf("Insert 0 to seqlist index 2:\n");
	seqlist_insert(&seqlist, 2, 0);
	print_seqlist(&seqlist);
	printf("Data 5 index:%d\n", seqlist_get_index(&seqlist, 5));
	printf("Index 4 data:%d\n", seqlist_get_value(&seqlist, 4));
	return 0;
}
