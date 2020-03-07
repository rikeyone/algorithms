//实现一个LRU list,并且支持先进先出

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct kv {
    int key;
    int value;
    struct kv *prev, *next;
};

struct lru {
    struct kv head;
    int size;
    int count;
} lru;

int init_lrc_cache(struct lru *lru, int size)
{
    if (!lru)
        exit(1);

    lru->size = size;
    lru->count = 0;
    lru->head.next = &lru->head;
    lru->head.prev = &lru->head;
}

int full(struct lru *lru)
{
    if (!lru)
        exit(1);

    if (lru->count == lru->size)
        return 1;
    else
        return 0;
}

int empty(struct lru *lru)
{
    if (!lru)
        exit(1);

    if (lru->count == 0)
        return 1;
    else
        return 0;
}

int get(struct lru *lru, int key)
{
    struct kv *temp;
    struct kv *head = &lru->head;

    if (!lru)
        exit(1);

    if (empty(lru))
        return -1;
    temp = head->next;
    while(temp != head) {
        if (temp->key == key) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = head->next;
            temp->prev = head;
            head->next->prev = temp;
            head->next = temp;
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

int put(struct lru *lru, int key, int value)
{
    struct kv *temp, *last;
    struct kv *head = &lru->head;

    if (!lru)
        exit(1);

    temp = (struct kv *)malloc(sizeof(struct kv));
    temp->key = key;
    temp->value = value;
    //insert
    temp->next = head->next;
    temp->prev = head;
    head->next->prev = temp;
    head->next = temp;
    lru->count++;
    while (lru->count > lru->size) {
        last = head->prev;
        last->prev->next = last->next;
        last->next->prev = last->prev;
        last->prev = NULL;
        last->next = NULL;
        free(last);
        lru->count--;
    }
    return 0;
}


int main(void)
{
    char command;
    int key, value, size;

    while(1) {
        scanf("%c", &command);
        if (command == 'p') { //put
            scanf("%d", &key);
            scanf("%d", &value);
            put(&lru, key, value);
        } else if (command == 'g'){ //get
            scanf("%d", &key);
            value = get(&lru, key);
            printf("get:key:%d value:%d\n", key, value);
        } else if (command == 'c') { //create
            scanf("%d", &size);
            init_lrc_cache(&lru, size);
        }
    }
    return 0;
}