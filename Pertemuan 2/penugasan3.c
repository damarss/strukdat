#include <stdio.h>

int main() {
    int Matriks_A[3][4];
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=4; j++) {
            printf("A(%d, %d): ", i, j);
            scanf("%i", &Matriks_A[i][j]);
        }
    }
    printf("\nMatriks_A:\n");
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=4; j++) {
           printf(" %i ", Matriks_A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
