#include <stdio.h>

void ingresarMatriz(int matriz[][100], int fila, int columna) {
    int num_ele;
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            printf("INGRESAR UN VALOR PARA LA POSICIÓN [%i][%i] DE LA MATRIZ: ", i, j);
            scanf("%i", &num_ele);
            matriz[i][j] = num_ele;
        }
    }
}

int buscarElementoMayor(int matriz[][100], int fila_bus, int columna) {
    int ele_may = matriz[fila_bus][0];
    for (int j = 1; j < columna; j++) {
        if (matriz[fila_bus][j] > ele_may) {
            ele_may = matriz[fila_bus][j];
        }
    }
    return ele_may;
}

int main() {
    int fila, columna, fila_bus;
    int matriz[100][100]; // Definimos un tamaño máximo para la matriz

    printf("INGRESAR UN VALOR PARA LA CANTIDAD DE FILAS DE LA MATRIZ: ");
    scanf("%i", &fila);
    printf("INGRESAR UN VALOR PARA LA CANTIDAD DE COLUMNAS DE LA MATRIZ: ");
    scanf("%i", &columna);

    ingresarMatriz(matriz, fila, columna);

    printf("INGRESAR UN VALOR PARA BUSCAR LA FILA DE LA MATRIZ: ");
    scanf("%i", &fila_bus);

    if (fila_bus >= fila || fila_bus < 0) {
        printf("Error: La fila ingresada no existe en la matriz.\n");
        return 1;
    }

    int ele_may = buscarElementoMayor(matriz, fila_bus, columna);
    printf("EL NÚMERO MÁS GRANDE DE LA FILA [%i] ES: %i\n", fila_bus, ele_may);

    return 0;
}
