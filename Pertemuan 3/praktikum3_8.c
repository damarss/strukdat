#include <stdio.h>

int main() {
    int a = 5;
    int *p;
    p = &a;
    printf("Alamat Memori: %p\n", p);
    printf("Nilai: %d\n", *p);
    return 0;
}
