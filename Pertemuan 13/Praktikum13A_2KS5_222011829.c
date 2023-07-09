#include <stdio.h>
#include <ctype.h>
#define MAX 100

void fill_data(int data[], int size) {
    printf("Input data: \n");
    for (int i = 0; i < size; i++) {
        printf("    Data[%d]= ", i);
        scanf("%d", &data[i]);
    }
}

void tampil_data(int data[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void pengurutan(char urut) {
    printf("Pilihan pengurutan ");
    switch (urut)
    {
    case 'N':
        printf("Naik\n");
        break;
    case 'T':
        printf("Turun\n");
        break;
    default:
        printf("Salah\n");
        return;
        break;
    }
}

void insertion_sort(int arr[], int n, char urut) {
    int i, j, key;
    printf("Menjalankan sorting dengan metode insertion sort\n");
    pengurutan(urut);
    for (int i = 0; i < n; i++) {
        key = arr[i];
        j = i - 1;
        switch (urut)
        {
        case 'N':
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
            break;
        case 'T':
            while (j >= 0 && arr[j] < key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
            break;
        default:
            return;
            break;
        }
    }
    printf("Data setelah diurutkan: ");
    tampil_data(arr, n);
}

void selection_sort(int data[], int size, char urut){
    printf("Menjalankan sorting dengan metode selection sort\n");
    pengurutan(urut);
    for(int step = 0; step < size - 1; step++){
        int min_max_idx = step;
        for(int i = step +1;i<size;i++) {
            switch (urut)
            {
            case 'N':
                if(data[i]<data[min_max_idx])
                    min_max_idx = i;
                break;
            case 'T':
                if(data[i]>data[min_max_idx])
                    min_max_idx = i;
                break;
            default:
                return;
                break;
            }
        }
        swap(&data[min_max_idx],&data[step]);
    }
    printf("Data setelah diurutkan: ");
    tampil_data(data, size);
}

void bubbleSort(int arr[], int n, char urut){
    int i, j;
    printf("Menjalankan sorting dengan metode bubble sort\n");
    pengurutan(urut);
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++) {
            switch (urut)
            {
            case 'N':
                if (arr[j] > arr[j+1])
                    swap(&arr[j], &arr[j+1]);
                break;
            case 'T':
                if (arr[j] < arr[j+1])
                    swap(&arr[j], &arr[j+1]);
                break;
            default:
                return;
                break;
            }
        }
    printf("Data setelah diurutkan: ");
    tampil_data(arr, n);
}

void merge(int arr[], int l, int m, int r, char urut){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        switch (urut)
        {
        case 'N':
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
            break;
        case 'T':
            if (L[i] > R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
            break;
        default:
            return;
            break;
        }
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, char urut){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, urut);
        mergeSort(arr, m + 1, r, urut);
        merge(arr, l, m, r, urut);
    }
}

void main() {
    int data[MAX];
    int size, metode;
    char urutan;
    printf("[]================================[]\n");
    printf("||      Program Sorting Data      ||\n");
    printf("[]================================[]\n");
    printf("Input Jumlah Data: ");
    scanf("%d", &size);
    printf("Metode Sorting yang Tersedia: \n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Bubble Sort\n");
    printf("Pilih metode sorting (1/2/3/4): ");
    scanf("%d", &metode);
    getchar();
    printf("Pilih pengurutan Naik/Turun(N/T): ");
    scanf("%c", &urutan);
    urutan = toupper(urutan);
    fill_data(data, size);
    printf("Data Anda: ");
    tampil_data(data, size);
ulg:
    switch (metode)
    {
    case 1:
        insertion_sort(data, size, urutan);
        break;
    case 2:
        selection_sort(data, size, urutan);
        break;
    case 3:
        printf("Menjalankan sorting dengan metode merge sort\n");
        pengurutan(urutan);
        mergeSort(data, 0, size - 1, urutan);
        printf("Data setelah diurutkan: ");
        tampil_data(data, size);
        break;
    case 4:
        bubbleSort(data, size, urutan);
        break;
    default:
        printf("Salah input pilihan! Silakan pilih metode yang ada\n");
        printf("Pilih metode sorting (1/2/3/4): ");
        scanf("%d", &metode);
        goto ulg;
        break;
    }
}