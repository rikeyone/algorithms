#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_node {
	char *key; //used for hash caculate
	void *value;
	struct hash_node *next;
};

#define HASH_TABLE_SIZE 32
#define ELF_HASH_ALGO

struct hash_table {
	struct hash_node *table[HASH_TABLE_SIZE];
	unsigned int bitmap;
};


void hash_table_init(struct hash_table *htable)
{
	memset(htable, 0, sizeof(struct hash_table));
	htable->bitmap = 0;
}

int hash_table_empty(struct hash_table *htable)
{
	return (htable->bitmap == 0);
}

/*
 * A simple string hash algorithm
 *
 * (Java is using the same algorithm)
 *
 * */
unsigned int string_hash_calculate(char *key)
{
	char *p = key;
	unsigned int h = 0;

	printf("using string hash algo!\n");

	while(*p) {
		h = (h << 5) - h + (unsigned int) (*p);	// h = h * 31 + val
		p++;
	}
	return h;
}

/*
 * elf hash algorithm
 *
 * Another good hash algorithm
 */

unsigned int elf_hash_calculate(char *key)
{
	unsigned int h = 0, g;
	char *p = key;

	printf("using elf hash algo!\n");

	while(*p) {
		h = (h << 4) + *p++;				//core calculate
		if ((g = (h & 0xF0000000U)) != 0)	//handle overflow case (which means top 4 bits are used)
			h ^= (g >> 24);					//XOR top 4 bits and low 4 bits
		h &= ~g;							//clean top 4 bits for next calculate
	}
	return h;
}

unsigned int hash_table_index(char *key)
{
	unsigned int hash, index;
#ifdef ELF_HASH_ALGO
	hash = elf_hash_calculate(key);
#else
	hash = string_hash_calculate(key);
#endif
	index = hash & (HASH_TABLE_SIZE - 1);	// hash % HASH_TABLE_SIZE

	printf("key:%s hash:%d [0x%x] index:%d\n", key, hash, hash, index);

	return index;
}

struct hash_node *create_hash_node(char *key, void *value)
{
	struct hash_node *node;

	node = (struct hash_node *)malloc(sizeof(struct hash_node));
	if(!node)
		return NULL;

	node->key = key;
	node->value = value;
	node->next = NULL;

	return node;
}

void free_hash_node(struct hash_node *node)
{
	free(node);
}

int hash_table_put(struct hash_table *htable, struct hash_node *node)
{
	int index;
	struct hash_node *head;

	index = hash_table_index(node->key);
	head = htable->table[index];
	if (head) {
		node->next = head->next;
		head->next = node;
	} else {
		htable->table[index] = node;
	}

	htable->bitmap = htable->bitmap | (1 << index);

	return 0;
}

struct hash_node *hash_table_get(struct hash_table *htable, char *key)
{
	int index;
	struct hash_node *head, *prev, *node;

	index = hash_table_index(key);
	if (htable->bitmap & (1 << index)) {
		head = htable->table[index];
		for(prev = head, node = head; node; prev = node, node = node->next) {
			printf("node->key:%s, key:%s\n", node->key, key);
			if (!strcmp(node->key, key))
				break;
		}
		prev->next = node->next;
		return node;
	}
	return NULL;
}


/***************test sample*********************/

int main(int argc, char *argv[])
{
	struct hash_table table;
	struct hash_node *node;

	hash_table_init(&table);
	node = create_hash_node("dog", "value1");
	hash_table_put(&table, node);
	node = create_hash_node("pig", "value2");
	hash_table_put(&table, node);
	node = create_hash_node("cat", "value3");
	hash_table_put(&table, node);
	node = create_hash_node("fish", "value4");
	hash_table_put(&table, node);

	node = hash_table_get(&table, "fish");
	printf("fish-->value:%s\n", (char *)node->value);
	free_hash_node(node);
	node = hash_table_get(&table, "dog");
	printf("dog-->value:%s\n", (char *)node->value);
	free_hash_node(node);
	node = hash_table_get(&table, "pig");
	printf("pig-->value:%s\n", (char *)node->value);
	free_hash_node(node);
	return 0;
}
