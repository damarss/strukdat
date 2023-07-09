#include <stdio.h>

int main() {
    int x, y;
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);
    if (x == y) {
        printf("%d sama dengan %d\n", x, y);
    } else {
        printf("%d tidak sama dengan %d\n", x, y);
        if (x < y) {
            printf("%d lebih kecil dari %d\n", x, y);
        } else if (x > y) {
            printf("%d lebih besar dari %d\n", x, y);
        }
    }

    return 0;
}
