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

void ingresarMatriz(int vector[MAX][MAX], int n) {
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &vector[i][j]);
        }
    }
}

void imprimirMatriz(int vector[MAX][MAX], int n) {
    printf("Matriz:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", vector[i][j]);
        }
        printf("\n");
    }
}

int validarIndices(int fi, int fj, int n) {
    return (fi >= 1 && fi <= n && fj >= 1 && fj <= n);
}

int main() {
    int n, fi, fj;
    int vector[MAX][MAX];

    printf("Ingrese el tamaño de la matriz (N): ");
    scanf("%d", &n);

    ingresarMatriz(vector, n);

    printf("Ingrese el índice de la fila i a intercambiar: ");
    scanf("%d", &fi);
    printf("Ingrese el índice de la fila j a intercambiar: ");
    scanf("%d", &fj);

    if (!validarIndices(fi, fj, n)) {
        printf("Índices de fila no válidos.\n");
        return 1;
    }

    intercambiarFilas(vector, n, fi, fj);
    printf("Matriz después de intercambiar las filas %d y %d:\n", fi, fj);
    imprimirMatriz(vector, n);

    return 0;
}
