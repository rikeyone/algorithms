//求list中的倒数第5个节点的值
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    int val;
    struct node *next;
};

struct node *create_node(int *value, int count)
{
    int i;
    struct node *node = NULL;
    struct node *head = NULL;
    struct node *temp = NULL;

    for (i = 0; i < count; i++) {
        node = (struct node *)malloc(sizeof(struct node));
        if (!node) {
            exit(1);
        }
        node->val = value[i];
        node->next = NULL;
        if (temp) {
            temp->next = node;
        }

        if (head == NULL) {
            head = node;
        }
        temp = node;
    }
    return head;
}

struct node *find_backward_node(struct node *head)
{
    struct node *fast = NULL, *slow = NULL;
    int k = 5;

    fast = head;
    slow = head;
    while(fast && k) {
        fast = fast->next;
        k--;
    }

    if (k)
        return NULL;

    while(fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

struct node *find_mid_node(struct node *head)
{
    struct node *fast = NULL, *slow = NULL;

    fast = head;
    slow = head;

    while(fast) {
        fast = fast->next;
        if (fast)
            fast = fast->next;
        else
            break;
        slow = slow->next;
    }
    return slow;
}

struct node *merge_sort_list(struct node *list1, struct node *list2)
{
    struct node *head = NULL;
    struct node *pos3 = NULL;

    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->val > list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }

    pos3 = head;

    while(list1 && list2) {
        if (list1->val > list2->val) {
            pos3->next = list1;
            pos3 = list1;
            list1 = list1->next;
        } else {
            pos3->next = list2;
            pos3 = list2;
            list2 = list2->next;
        }
    }
    if (list1) {
        pos3->next = list1;
    } else if (list2) {
        pos3->next = list2;
    } else {
        pos3->next = NULL;
    }
    return head;
}

int main(void)
{
    int count = 0, i = 0;
    int buf[1024] = {0};
    struct node *list = NULL, *list1 = NULL;
    struct node *node = NULL;

    scanf("%d", &count);
    for(i = 0; i < count; i++) {
        scanf("%d", &buf[i]);
    }
    list1 = create_node(buf, count);

    scanf("%d", &count);
    for(i = 0; i < count; i++) {
        scanf("%d", &buf[i]);
    }
    list = create_node(buf, count);


    node = find_backward_node(list);
    if (node)
        printf("%d\n", node->val);
    else
    {
        printf("not long enough\n");
    }
    node = find_mid_node(list);
    if (node)
        printf("mid:%d\n", node->val);
    else
        printf("not long enough\n");

    node = merge_sort_list(list, list1);
    while(node) {
        printf("%d ", node->val);
        node = node->next;
    }
    return 0;
}