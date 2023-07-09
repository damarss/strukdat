#include <stdio.h>
#include <stdlib.h>

int noIndex = 0;

struct node {
    int data;
    struct node *next;
    int index;
};


struct node *createNode(int new_data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    noIndex++;
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->index = noIndex;

    return new_node;
}

struct node *insertNode(struct node *head, int new_data) {
    struct node *new_node = createNode(new_data);
    struct node *cursor = head;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    cursor->next = new_node;

    return head;
}

struct node *deleteSentinel(struct node *head) {
    struct node *cursor = head;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    struct node *temp = cursor->next;
    cursor->next = NULL;
    free(temp);
    return head;
}

int sequentialSearch(struct node *head, int data) {
    struct node *cursor = head;
    while (cursor != NULL) {
        if (cursor->data == data) {
            return cursor->index;
        }
        cursor = cursor->next;
    }
    return -1;
}

int sequentialSearchWithSentinel(struct node *head, int data) {
    struct node *sentinel = createNode(data);
    struct node *temp = head;
    while  (temp->next = NULL) {
        temp = temp->next;
    }
    temp->next = sentinel;
    struct node *cursor = head;
    while (cursor->data != data) {
        cursor = cursor->next;
    }
    if (cursor == sentinel) {
        deleteSentinel(head);
        return -1;
    }
    deleteSentinel(head);
    return cursor->index;
}

void displayNode(struct node *head) {
    struct node *cursor = head;
    printf("Isi Node: ");
    while (cursor != NULL) {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
    printf("\n\n");
}

int main() {
    struct node *head = NULL;
    head = createNode(12); //1
    head = insertNode(head, 1); //2
    head = insertNode(head, 7); //3
    head = insertNode(head, 0); //4
    head = insertNode(head, 8); //5   
    head = insertNode(head, 1); //6
    head = insertNode(head, 9); //7
    head = insertNode(head, 4); //8
    head = insertNode(head, 5); //9
    
    displayNode(head);
    int search = sequentialSearch(head, 21 );
    printf("Cari data\n");
    if (search != -1) {
        printf("Data ditemukan pada node ke %d\n", search);
    } else {
        printf("Data tidak ditemukan\n");
    }

    return 0;
}