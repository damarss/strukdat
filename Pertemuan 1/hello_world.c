#include <stdio.h>

int main() {
    int bulat;
    float des = 17.45f;
    char kar = 'A';
    char strong[20] = "Arin";

    printf("Angka: ");
    scanf("%d", &bulat);
    getchar();
    printf("%d\n", bulat);

    printf("Real: ");
    scanf("%f", &des);
    getchar();
    printf("%.3f\n", des);

    printf("Karakter: ");
    scanf("%c", &kar);
    getchar();
    printf("%c\n", kar);

    printf("Nama: ");
    scanf("%[^\n]", strong);
    getchar();
    printf("%s\n", strong);

    return 0;
}
