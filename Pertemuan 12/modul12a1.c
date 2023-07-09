#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size) {
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("Input data ke-%d: ", i+1);
        scanf("%d", &data[i]);
    }
}

int seq_search(int data[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (data[i] == x)
            return i;
    }
    return -1;
}

int seq_search_asc(int data[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (data[i] == x)
            return i;
        else if (data[i] > x)
            return -1;
    }
}

int seq_search_desc(int data[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (data[i] == x)
            return i;
        else if (data[i] < x)
            return -1;
    }
}

void main() {
    int data[MAX];
    int size, x, pilih;
    printf("1. Data acak\n");
    printf("2. Data urut ascending\n");
    printf("3. Data urut descending\n");
    printf("Pilihan: ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        printf("Data acak\n");
        fill_data(data, &size);
        printf("Nilai yang mau dicari: ");
        scanf("%d", &x);
        if (seq_search(data, size, x) == -1)
            printf("Data tidak ditemukan\n");
        else
            printf("Data ditemukan pada indeks ke-%d\n", seq_search(data, size, x));
        break;
    case 2:
        printf("Data urut ascending\n");
        fill_data(data, &size);
        printf("Nilai yang mau dicari: ");
        scanf("%d", &x);
        if (seq_search_asc(data, size, x) == -1)
            printf("Data tidak ditemukan\n");
        else
            printf("Data ditemukan pada indeks ke-%d\n", seq_search_asc(data, size, x));
        break;
    case 3:
        printf("Data urut descending\n");
        fill_data(data, &size);
        printf("Nilai yang mau dicari: ");
        scanf("%d", &x);
        if (seq_search_desc(data, size, x) == -1)
            printf("Data tidak ditemukan\n");
        else
            printf("Data ditemukan pada indeks ke-%d\n", seq_search_desc(data, size, x));
        break;
    default:
        break;
    }
    getchar();
}