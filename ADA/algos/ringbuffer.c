#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct {
    struct node *head;
    struct node *tail;
    int max_size;
} queue;

int buf_size(queue *buf) {
    int count = 0;
    node *temp = buf->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert(queue *buf, int num) {
    node *new = malloc(sizeof(node));
    new->next = NULL;
    new->value = num;
    if (buf->head == NULL) {
        buf->head = new;
        buf->tail = new;
    } else if (buf_size(buf) == buf->max_size) {
        buf->tail->next = new;
        new->next = buf->head->next;
        free(buf->head);
        buf->head = new;
        buf->tail = new;
    } else {
        buf->tail->next = new;
        buf->tail = new;
    }
}

void print(queue buf) {
    node *temp = buf.head;
    printf("[");
    do {
        printf(" %d ", temp->value);
        temp = temp->next;
    } while (temp != NULL && temp != buf.head);
    printf("]\n");
}

void cleanup(queue *buf) {
    node *temp1 = buf->head;
    node *temp2;
    do {
        temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    } while (temp1 != NULL && temp1 != buf->head);
    buf->head = NULL;
    buf->tail = NULL;
}

void init(queue *buf, int size) {
    buf->head = NULL;
    buf->tail = NULL;
    buf->max_size = size;
}

int main(int argc, char **argv) {

    queue buf;

    init(&buf, 5);

    insert(&buf, 1);
    insert(&buf, 2);
    insert(&buf, 3);
    insert(&buf, 4);
    insert(&buf, 5);
    insert(&buf, 6);
    insert(&buf, 7);

    print(buf);

    cleanup(&buf);

    return 0;
}
