#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int priority;
    struct node *next;
};

typedef struct node *ptrnode;

ptrnode newNode(int d, int p) {
    ptrnode new_node = (ptrnode)malloc(sizeof(struct node));
    new_node->data = d;
    new_node->priority = p;
    new_node->next = NULL;
}

void enqueue(ptrnode *head, int d, int p) {
    ptrnode temp = newNode(d,p);
    if ((*head)->priority < p) {
        temp->next = (*head);
        (*head) = temp;
    } else {
        ptrnode cursor = (*head);
        while (cursor->next != NULL && cursor->next->priority >= p) {
            cursor = cursor->next;
        }
        temp->next = cursor->next;
        cursor->next = temp;
    }
}

void dequeue(ptrnode *head) {
    ptrnode temp = (*head);
    (*head) = (*head)->next;
    free(temp);
}

void display(ptrnode head) {
    ptrnode cursor = head;
    printf("Isi Queue: ");
    while (cursor != NULL) {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

void main() {
    ptrnode head = newNode(2,1);
    enqueue(&head,12,0);
    enqueue(&head,7,2);
    enqueue(&head,51,1);
    enqueue(&head,25,3);
    display(head);
    dequeue(&head);
    display(head);
}