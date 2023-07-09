#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *ptrnode;

ptrnode head = NULL;
int jumnode; //jumlah node

ptrnode insert(int nilai) {
    ptrnode p, q;
    p = (ptrnode)malloc(sizeof(struct node));
    p->data = nilai;
    p->next = NULL;
    if (head == NULL) {
        head = p;
    } else {
        q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
    return head;
}

void isi_data() {
    int k;
    printf("Input jumlah node: ");
    scanf("%d", &jumnode);
    for (int j = 1; j <= jumnode; j++) {
        printf("Input data ke-%d: ", j);
        scanf("%d", &k);
        head = insert(k);
    }
}

int search(int x) {
    int j = 1;
    ptrnode tmp = head;
    while (tmp != NULL) {
        if (x == tmp->data) {
            return j;
        } else if (tmp->data > x) {
            return -1;
        } else {
            tmp = tmp->next;
            j++;
        }
    }
}

void bersihkan_memori() {
    while (head != NULL) {
        ptrnode tmp = head;
        head = head->next;
        tmp->next = NULL;
        free(tmp);
    }
}

void main() {
    int pil = 0;
    int x;
    while (pil != 4) {
        printf("1. Input data\n");
        printf("2. Cari data\n");
        printf("3. Bersihkan memori\n");
        printf("4. Keluar\n");
        printf("\nPilihan Anda: ");
        scanf("%d", &pil);
        switch (pil)
        {
        case 1:
            isi_data();
            break;
        case 2:
            printf("Input nilai yang mau dicari: ");
            scanf("%d", &x);
            if (search(x) == -1) 
                printf("data tidak ditemukan\n");
            else 
                printf("data ditemukan di node ke-%d\n",search(x));
            break;
        case 3:
            bersihkan_memori();
            printf("Memori telah dibersihkan\n");
            break;
        case 4:
            printf("Terima kasih telah menggunakan program ini\n");
            break;
        default:
            break;
        }
    }
}