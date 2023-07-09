#include <stdio.h>

int main() {
    int x[1000000];
    for (int i = 0; i < 1000000; i++) {
        x[i] = 4;
    }
    x[9999] = 7;
    for (int i = 0; i < 1000000; i++) {
        if (x[i] == 7) {
            printf("Data ditemukan\n");
            return;
        }
    }
    printf("Data tidak ditemukan\n");
    
    return 0;
}