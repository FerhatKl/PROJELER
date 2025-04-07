#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int X[2][3], Y[3][2];
    srand(time(NULL));

    for (int i=0;i<2; i++)
        for (int j=0;j<3;j++)
            X[i][j] = rand()%100 + 1;

    for (int i=0;i<3;i++)
        for (int j=0;j<2;j++)
            Y[i][j] = rand()%100 + 1;

    printf("\nMatrix X:\n");
    for (int i=0;i<2;i++) {
        for (int j=0;j<3;j++)
            printf("%d\t", X[i][j]);
        printf("\n");
    }

    printf("\nMatrix Y:\n");
    for (int i=0;i<3;i++) {
        for (int j=0;j<2;j++)
            printf("%d\t", Y[i][j]);
        printf("\n");
    }

    if (2 == 3 && 3 == 2) {
        int toplam[2][3];
        for (int i=0;i<2;i++) {
            for (int j = 0; j < 3; j++) {
                toplam[i][j] = X[i][j] + Y[i][j];
            }
        }

        printf("\nToplam:\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d\t", toplam[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("\nToplanamaz\n");
    }

    int carpim[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            carpim[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                carpim[i][j] += X[i][k] * Y[k][j];
            }
        }
    }

    printf("\nCarpým:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", carpim[i][j]);
        }
        printf("\n");
    }
}
