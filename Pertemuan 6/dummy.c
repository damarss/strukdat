#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node *stacknode;

stacknode createNode(int nilai) {
    stacknode new_node;
    new_node = (stacknode)malloc(sizeof(struct node));
    new_node->value = nilai;
    new_node->next = NULL;

    return new_node;
}

void push(int nilai, stacknode *top) {
    stacknode new_node = createNode(nilai);
    new_node->next = *top;
    *top = new_node;
}

int pop(stacknode *top) {
    stacknode temp;
    temp = *top;
    *top = (*top)->next;
    int data = temp->value;
    temp->next = NULL;
    free(temp);

    return data;
}

void konversiBiner(int nilai) {
    stacknode stack = NULL;
    if (nilai == 0) {
        printf("Hasil konversi biner = 0");
    } else {
        printf("Hasil konversi biner (positif)= ");
        while (nilai > 0) {
            push(nilai % 2, &stack);
            nilai /= 2;
        }
        while (stack != NULL) {
            printf("%d", pop(&stack));
        }
        printf("\n");
    }
}

void konversiNegatif(int nilai) {
    stacknode stack = NULL;
    stacknode temp = NULL;
    if (nilai == 0) {
        printf("Hasil konversi biner (negatif)= 0");
    } else {
        printf("Hasil konversi biner (negatif)= ");
        while (nilai > 0) {
            push(nilai % 2, &stack);
            nilai /= 2;
        }
        while (stack != NULL) {
            push(!(pop(&stack)), &temp);
        }
        while (temp != NULL) {
            printf("%d", pop(&temp));
        } /*
        int kor = 1;
        while (temp != NULL) {
            if (temp->value == 1 && kor == 1) {
                temp->value = 0;
            } else if (kor == 0) {
                temp->value += kor;
                if (kor>0) {
                    kor--;
                }
            }
            temp = temp->next;
            printf("%d", pop(&temp));
        } */
        printf("\n");
    }
}

void konversiOktal(int nilai) {
    stacknode stack = NULL;
    if (nilai == 0) {
        printf("Hasil konversi biner = 0");
    } else {
        printf("Hasil konversi biner = ");
        while (nilai > 0) {
            push(nilai % 8, &stack);
            nilai /= 8;
        }
        while (stack != NULL) {
            printf("%d", pop(&stack));
        }
        printf("\n");
    }
}

void tampil(stacknode *top) {
    while (top != NULL) {
        printf("%d", pop(top));
    }
}

void main() {
    stacknode top = NULL;
    int bilangan, pilih, pilih_2;
    printf("Program Konversi Bilangan\n");
    printf("Masukkan bilangan (tanpa tanda): ");
    scanf("%d", &bilangan);
    printf("=============================\n");
    printf("Pilih Menu Berikut: \n");
    printf("1. Konversi Desimal ke Biner\n");
    printf("2. Konversi Desimal ke Oktal\n");
    printf("=============================\n");
    printf("Pilihan Anda: ");
    scanf("%d", &pilih);
    printf("-----------------------------\n");
    if (pilih == 1) {
        konversiBiner(bilangan);
        konversiNegatif(bilangan);
    } else if (pilih == 2) {
        konversiOktal(bilangan);
    }
}
