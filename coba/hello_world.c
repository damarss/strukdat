#include <stdio.h>

int main() {
    char a,b;
    printf("a = ");
    scanf("%c", &a);
    getchar();
    printf("b = ");
    scanf("%c", &b);
    getchar();
    printf("a = %c\nb = %c", a,b);
    getchar();
}
