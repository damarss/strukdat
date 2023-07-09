#include <stdio.h>
#include <math.h>
#define MAX 100

void inputData(int data[], int *size) {
    printf("Jumlah data sampel: ");
    scanf("%d", size);
    printf("Input data: \n");
    for (int i = 0; i < *size; i++) {
        printf("Data sampel ke-%d: ", i+1);
        scanf("%d", &data[i]);
    }
}

void tampilData(int data[], int size) {
    printf("Data sampel: \n");
    printf("    %-2s | Data\n", "No");
    printf("  ===================\n");
    for (int i = 0; i < size; i++) {
        printf("    %-2d | %d\n", i+1, data[i]);
    }
}

float mean(int data[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum/size;
}

float sd(int data[], int size) {
    float xbar = mean(data, size);
    float sum = 0;
    for (int i = 0; i < size; i++) {
        float temp = pow((data[i] - xbar), 2);
        sum += temp;
    }
    return sum/(size-1);
}

float titikKritis(int data[], int size, float alpha) {
    float se = sd(data, size)/sqrt(size); //mencari standard error
    float z;
    
}

void main() {
    int data[MAX];
    int size, pilih;
    inputData(data, &size);
    tampilData(data, size);
    printf("Rata-rata sampel = %.3f\n", mean(data, size));
    printf("Standar deviasi sampel = %.3f\n", sd(data, size));
    printf("Tentukan jenis hipotesis:\n"
    "   1. Uji dua arah\n"
    "   2. Uji satu arah kiri\n"
    "   3. Uji satu arah kanann");
    printf("Input: ");
    scanf("%d", &pilih);
}