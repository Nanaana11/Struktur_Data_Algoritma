#include <stdio.h>
#include <stdlib.h>

//deklarasi struct tnode
struct tnode {
    int data;
    struct tnode *next;
};

//bil di akhir single linked-list
void insertLast(int bil, struct tnode **head, struct tnode **tail) {
    struct tnode *newNode = (struct tnode*)malloc(sizeof(struct tnode));
    newNode->data = bil;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

//bil di awal single linked-list
void insertFirst(int bil, struct tnode **head, struct tnode **tail) {
    struct tnode *newNode = (struct tnode*)malloc(sizeof(struct tnode));
    newNode->data = bil;
    newNode->next = *head;

    *head = newNode;
    if (*tail == NULL) {
        *tail = newNode;
    }
}

//show nilai single linked-list dari awal ke akhir
void printLinkedList(struct tnode *head) {
    struct tnode *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct tnode *head, *tail;
    head = NULL;
    tail = NULL;

    insertFirst(10, &head, &tail);
    insertFirst(20, &head, &tail);
    insertFirst(30, &head, &tail);

    insertLast(40, &head, &tail);
    insertLast(50, &head, &tail);
    insertLast(60, &head, &tail);

    printLinkedList(head);
    return 0;
}
