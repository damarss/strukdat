#include <stdio.h>

int tamha(x) {
    x += 1;
    return x;
}

int main() {
    printf("Hello, World!");
    int x = 4;
    printf("\n%d", tamha(x));
    return 69;
}