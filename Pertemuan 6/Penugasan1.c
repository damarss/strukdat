#include <stdio.h>
#include <stdlib.h>

struct stack {
    int value;
    struct stack *next;
};

typedef struct stack* ptrstack;
ptrstack top;

void initializestack() {
    top = NULL;
}

void createNode(int nilai) {
    ptrstack s;
    s = (ptrstack*)malloc(sizeof(struct stack));
    s->value = nilai;
    s->next = top;
    top = s;
}

void pushNode(ptrstack stackNode, int)

void popNode() {
    ptrstack tmp;
    tmp = top;
    top = top->next;
    free(tmp);
}

void displayStack(ptrstack head) {
    if (head != NULL) {
        printf("%d", head->value);
        displayStack(head->next);
    }
}

void konversiBiner(int nilai, ptrstack s) {
    if (nilai == 0) {
        printf("Hasil konversi ke biner = 0");
    } else {
        while (nilai > 0) {
            pushNode()
        }
        printf("Hasil konversi ke biner = ");
        for (int i = s.jml_item; i > 0; i--) {
            printf("%d", pop(&s));
        }
    }
}

void konversiOktal(int nilai, int sisa, stack s) {
    if (nilai == 0) {
        printf("Hasil konversi ke biner = 0");
    } else {
        for (int n = nilai; n > 0; n = n/2) {
            sisa = n%2;
            push(sisa, &s);
        }
        printf("Hasil konversi ke biner = ");
        for (int i = s.jml_item; i > 0; i--) {
            printf("%d", pop(&s));
        }
    }
}

int main() {
    stack tumpukan;
    int bil_desimal;
    int sisa_bagi;

    printf("Program konversi Desimal ke Biner\n");
    initializestack(&tumpukan);
    printf("Top saat diinitialize %d\n", tumpukan.jml_item);
    printf("Masukkan bilangan desimal = ");
    scanf("%d", &bil_desimal);

    konversiBiner(bil_desimal, sisa_bagi, tumpukan);

    printf("\n--------------------------------");
    return 0;
}
