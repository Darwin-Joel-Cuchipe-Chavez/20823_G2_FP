#include <stdio.h>
#define MAX 100

void ingresarMatriz(int matriz[][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("INGRESAR UN VALOR PARA LA POSICIÓN [%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int matriz[][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Corrected function name to "matrizTraspuesta"
void matrizTraspuesta(int matriz[][MAX], int traspuesta[][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            traspuesta[j][i] = matriz[i][j]; // Intercambiamos filas y columnas
        }
    }
}

int main() {
    int filas, columnas;
    int matriz[MAX][MAX], traspuesta[MAX][MAX];

    printf("INGRESAR EL NÚMERO DE FILAS: ");
    scanf("%i", &filas);
    printf("INGRESAR EL NÚMERO DE COLUMNAS: ");
    scanf("%i", &columnas);

    printf("INGRESAR LOS ELEMENTOS DE LA MATRIZ:\n");
    ingresarMatriz(matriz, filas, columnas);

    // Corrected function call to "matrizTraspuesta"
    matrizTraspuesta(matriz, traspuesta, filas, columnas);

    printf("MATRIZ ORIGINAL:\n");
    imprimirMatriz(matriz, filas, columnas);

    printf("MATRIZ TRASPUESTA:\n");
    imprimirMatriz(traspuesta, columnas, filas);

    return 0;
}
