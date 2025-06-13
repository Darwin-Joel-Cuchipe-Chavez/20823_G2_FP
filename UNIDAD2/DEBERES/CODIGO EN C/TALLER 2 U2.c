#include <stdio.h>
#define MAX 100

void intercambiarFilas(int vector[MAX][MAX], int n, int fi, int fj) {
    int temp;
    for (int j = 1; j <= n; j++) {
        temp = vector[fi][j];
        vector[fi][j] = vector[fj][j];
        vector[fj][j] = temp;
    }
}

int main() {
    int n, i, j, fi, fj;
    int vector[MAX][MAX];
    printf("Ingrese el tamaño de la matriz (N): ");
    scanf("%d", &n);
    printf("Ingrese los elementos de la matriz:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &vector[i][j]);
        }
    }
    printf("Ingrese el índice de la fila i a intercambiar: ");
    scanf("%d", &fi);
    printf("Ingrese el índice de la fila j a intercambiar: ");
    scanf("%d", &fj);

    if (fi < 0 || fi > n || fj < 0 || fj > n) {
        printf("Índices de fila no válidos.\n");
        return 1;
    }
    intercambiarFilas(vector, n, fi, fj);
    printf("Matriz después de intercambiar las filas %d y %d:\n", fi, fj);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", vector[i][j]);
        }
        printf("\n");
    }
    return 0;
}
