#include <stdio.h>

int main() {
    char karakter;
    int bil_bulat;
    float bil_desimal;
    double bil_desimal2;
    printf("Jumlah memori pada masing-masing tipe data: \n");
    printf("1. char   = %d byte\n", sizeof(karakter));
    printf("2. int    = %d byte\n", sizeof(bil_bulat));
    printf("3. float  = %d byte\n", sizeof(bil_desimal));
    printf("4. double = %d byte\n", sizeof(bil_desimal2));

    return 0;
}
