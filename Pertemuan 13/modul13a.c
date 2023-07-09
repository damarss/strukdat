#include <stdio.h>
#define MAX 100

void fill_data(int data[], int *size) {
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data: \n");
    for (int i = 0; i < *size; i++) {
        printf("Data[%d] = ", i);
        scanf("%d", &data[i]);
    }
}

void tampil_data(int data[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (int i = 0; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void main() {
    int data[MAX];
    int size;
    fill_data(data, &size);
    printf("Data sebelum diurutkan:\n");
    tampil_data(data, size);
    printf("\n");
    insertion_sort(data, size);
    printf("Data setelah diurutkan:\n");
    tampil_data(data, size);
}