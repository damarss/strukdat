#include <stdio.h>

int main() {
    int panjang, lebar, luas, keliling;
    printf("Program Menghitung Luas dan Keliling Persegi Panjang\n");
    printf("====================================================\n");

    printf("Panjang: ");
    scanf("%d", &panjang);

    printf("Lebar  : ");
    scanf("%d", &lebar);

    luas = panjang*lebar;
    keliling = 2*(panjang+lebar);

    printf("\n-------------------------------------------------\n");
    printf("Luas Persegi Panjang = %d * %d = %d\n", panjang, lebar, luas);
    printf("Keliling Persegi Panjang = 2 * (%d + %d) = %d\n", panjang, lebar, keliling);
    printf("-------------------------------------------------\n");

    return 0;
}
