#include <stdio.h>

int main() {
    int matriz[3][7] = {
        {1, 2, 3, 4, 5, 6, 7},
        {3, 5, 6, 2, 4, 7, 1},
        {6, 7, 5, 4, 2, 1, 3}
    };

    int traspuesta[7][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            traspuesta[j][i] = matriz[i][j];
        }
    }
    printf("Matriz traspuesta:\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", traspuesta[i][j]);
        }
        printf("\n");
    }
    return 0;
}
