#include <stdio.h>
#include <string.h>

struct Buku {
    char judul[50];
    char pengarang[50];
    int id;
};

int main() {
    struct Buku Buku1, Buku2;

    /* Spesifikasi Buku 1 */
    strcpy(Buku1.judul, "C Programming");
    strcpy(Buku1.pengarang, "Nuha Ali");
    Buku1.id = 6495407;

    /* Spesifikasi Buku 2 */
    strcpy(Buku2.judul, "Telecom Billing");
    strcpy(Buku2.pengarang, "Zara Ali");
    Buku2.id = 6495700;

    /* Cetak informasi Buku 1 */
    printf("Judul Buku 1: %s\nPengarang Buku 1: %s\nId Buku 1: %d\n\n", Buku1.judul, Buku1.pengarang, Buku1.id);
    printf("Judul Buku 2: %s\nPengarang Buku 2: %s\nId Buku 2: %d\n", Buku2.judul, Buku2.pengarang, Buku2.id);


    return 0;
}
