//基于数组设计一个环形缓冲区，定长为N的FIFO对了
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ringbuf {
    int *data;
    int max;
    int head;
    int tail;
    int count;
};

struct ringbuf buf;

void print_ringbuf(struct ringbuf *buf)
{
    printf("max:%d head:%d tail:%d count:%d \n",
        buf->max, buf->head, buf->tail, buf->count);
}

int buffer_init(struct ringbuf *buf, int size)
{
    buf->max = size + 1;
    buf->head = 0;
    buf->tail = 0;
    buf->count = 0;
    buf->data = (int *)malloc(buf->max * sizeof(int));
    if (buf->data == NULL)
        return -1;
    print_ringbuf(buf);
    return 0;
}

int empty(struct ringbuf *buf)
{
    if (buf->head == buf->tail)
        return 1;
    else
        return 0;

}

int full(struct ringbuf *buf)
{
    if (buf->count == buf->max - 1)
        return 1;
    else
        return 0;
}

void increase_head(struct ringbuf *buf)
{
    buf->head = (buf->head + 1) % buf->max;

    if (buf->tail >= buf->head)
        buf->count = buf->tail - buf->head;
    else
        buf->count = buf->tail + buf->max - buf->head;
}

void increase_tail(struct ringbuf *buf)
{
    buf->tail = (buf->tail + 1) % buf->max;

    if (full(buf))
        buf->head = (buf->head + 1) % buf->max;

    if (buf->tail >= buf->head)
        buf->count = buf->tail - buf->head;
    else
        buf->count = buf->tail + buf->max - buf->head;
}

int take(struct ringbuf *buf)
{
    int value;

    if (empty(buf))
        return -1;

    value = buf->data[buf->head];
    increase_head(buf);
    print_ringbuf(buf);
    return value;
}

bool put(struct ringbuf *buf, int value)
{
    buf->data[buf->tail] = value;
    increase_tail(buf);
    print_ringbuf(buf);
    return true;
}

int main(void)
{
    char command;
    int value;

    while(1) {
        scanf("%c", &command);
        if (command == 'p') { //put
            scanf("%d", &value);
            put(&buf, value);
        } else if (command == 't'){ //take
            value = take(&buf);
            printf("Take:%d\n", value);
        } else if (command == 'c') { //create
            scanf("%d", &value);
            buffer_init(&buf, value);
        }
    }
    return 0;
}