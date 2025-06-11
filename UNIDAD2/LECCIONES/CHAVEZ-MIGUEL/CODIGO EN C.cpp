#include <stdio.h>
#include <limits.h> // Para usar INT_MIN

int main() {
    int filas, columnas;

    // 1. Ingreso de la Matriz
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // 2. Selección de la Fila
    int filaSeleccionada;
    printf("Ingrese el número de la fila que desea analizar (0 a %d): ", filas - 1);
    scanf("%d", &filaSeleccionada);

    // Validar que la fila seleccionada está en el rango
    if (filaSeleccionada < 0 || filaSeleccionada >= filas) {
        printf("Error: Número de fila fuera de rango.\n");
        return 1;
    }

    // 3. Cálculo del Valor Máximo
    int maximo = INT_MIN; // Inicializar con el valor más pequeño de un entero
    for (int j = 0; j < columnas; j++) {
        if (matriz[filaSeleccionada][j] > maximo) {
            maximo = matriz[filaSeleccionada][j];
        }
    }

    // 4. Salida del Resultado
    printf("El valor máximo en la fila %d es: %d\n", filaSeleccionada, maximo);

    return 0;
}
