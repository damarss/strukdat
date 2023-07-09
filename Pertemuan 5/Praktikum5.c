#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *prev;
    struct node *next;
};

typedef struct node *ptrnode;

ptrnode createNode(int nilai) {
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->prev = NULL;
    p->next = NULL;
    return(p);
}

void output_forward(ptrnode head) {
    ptrnode tmp = head;
    printf("Isi linked list forward: ");
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void output_backward(ptrnode head) {
    //mencari tail
    ptrnode stail = head;
    while(stail->next != NULL) {
        stail = stail->next;
    }
    printf("Isi linked list backward: ");
    while (stail != NULL) {
        printf("%d ", stail->value);
        stail = stail->prev;
    }
    printf("\n");
}

ptrnode insertNode_head(ptrnode head, int value) {
    ptrnode new_node = createNode(value);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    return head;
}

ptrnode insertNode_tail(ptrnode head, int value) {
    ptrnode new_node = createNode(value);
    ptrnode tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;

    return tail;
}

ptrnode deleteNode_head(ptrnode head) {
    ptrnode first = head;
    head = head->next;
    head->prev = NULL;
    first->next = NULL;
    free(first);

    return head;
}

ptrnode deleteNode_tail(ptrnode head) {
    ptrnode tail = head;
    while (tail->next !=NULL ){
        tail = tail->next;
    }
    ptrnode temp = tail;
    tail = tail->prev;
    tail->next = NULL;

    free(temp);
    return tail;
}

void main() {
    ptrnode head = NULL;
    head = (ptrnode)malloc(sizeof(struct node));
    head->value = 10;
    head->prev = NULL;
    head->next = NULL;

    struct node node_dua;
    ptrnode dua = &node_dua;
    dua->value = 20;
    dua->prev = NULL;
    dua->next = NULL;

    head->next = dua;
    dua->prev = head;

    ptrnode tiga = NULL;
    ptrnode empat = NULL;

    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));

    dua->next = tiga;
    tiga->value = 30;
    tiga->prev = dua;
    tiga->next = empat;
    empat->value = 40;
    empat->prev = tiga;
    empat->next = NULL;

    ptrnode lima = createNode(50);
    empat->next = lima;
    lima->prev = empat;

    output_forward(head);
    output_backward(head);

    //insert head
    head = insertNode_head(head, 31);
    head = insertNode_head(head, 41);
    printf("\nSetelah penambahan head\n");
    printf("=========================\n");
    output_forward(head);
    output_backward(head);

    //insert tail
    ptrnode tail = insertNode_tail(head, 17);
    printf("\nSetelah penambahan tail\n");
    printf("=========================\n");
    output_forward(head);
    output_backward(head);

    //hapus head
    head = deleteNode_head(head);
    printf("\nSetelah head dihapus\n");
    printf("=========================\n");
    output_forward(head);
    output_backward(head);

    //hapus tail
    tail = deleteNode_tail(head);
    printf("\nSetelah tail dihapus\n");
    printf("=========================\n");
    output_forward(head);
    output_backward(head);
}
