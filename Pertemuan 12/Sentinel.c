#include <stdio.h>
#define MAX 100

void fill_data(int data[], int *size) {
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("Input data ke-%d: ", i+1);
        scanf("%d", &data[i]);
    }
}

int search(int data[], int x) {
    int i = 0;
    while (data[i] != x) {
        i++;
    }
}

int main() {
    int data[MAX];

    return 0;
}