#include <stdio.h>

int main() {
    char nama[30], nim[10];
    float nilai_kuis, nilai_uts, nilai_uas, nilai_akhir;

    printf("Program Input Data Mahasiswa");
    printf("\n============================\n");

    printf("Masukkan NIM: ");
    scanf("%s", nim);

    printf("Masukkan Nama: ");
    scanf(" %[^\n]", nama);

    printf("Masukkan Nilai Kuis: ");
    scanf("%f", &nilai_kuis);

    printf("Masukkan Nilai UTS: ");
    scanf("%f", &nilai_uts);

    printf("Masukkan Nilai UAS: ");
    scanf("%f", &nilai_uas);

    nilai_akhir = (0.2*nilai_kuis)+(0

    printf("\nData Mahasiswa\n");
    printf("==================\n");
    printf("NIM        : %s\n", nim);
    printf("Nama       : %s\n", nama);
    printf("Nilai Kuis : %.2f\n", nilai_kuis);
    printf("Nilai UTS  : %.2f\n", nilai_uts);
    printf("Nilai UAS  : %.2f\n", nilai_uas);
    printf("Nilai Akhir: %.2f\n", nilai_akhir);
    printf("==================\n");

    return 0;
}
