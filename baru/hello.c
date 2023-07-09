#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *ptrnode;

ptrnode createNode(int newData) {
    ptrnode newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = NULL;
}

int main() {
    ptrnode head = createNode(7);
    ptrnode node1 = createNode(2);
    ptrnode node2 = createNode(3);

    head->next = node1;
    node1->next = node2;

    printf("Isi linked list: ");
    ptrnode cursor = head;
    while (cursor != NULL) {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
    getchar();
}