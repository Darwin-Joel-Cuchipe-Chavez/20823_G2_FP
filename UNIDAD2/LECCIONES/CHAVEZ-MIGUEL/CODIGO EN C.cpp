#include <stdio.h>
#include <limits.h> // Para usar INT_MIN

int main() {
    int filas, columnas;

    // 1. Ingreso de la Matriz
    printf("Ingrese el n�mero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el n�mero de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // 2. Selecci�n de la Fila
    int filaSeleccionada;
    printf("Ingrese el n�mero de la fila que desea analizar (0 a %d): ", filas - 1);
    scanf("%d", &filaSeleccionada);

    // Validar que la fila seleccionada est� en el rango
    if (filaSeleccionada < 0 || filaSeleccionada >= filas) {
        printf("Error: N�mero de fila fuera de rango.\n");
        return 1;
    }

    // 3. C�lculo del Valor M�ximo
    int maximo = INT_MIN; // Inicializar con el valor m�s peque�o de un entero
    for (int j = 0; j < columnas; j++) {
        if (matriz[filaSeleccionada][j] > maximo) {
            maximo = matriz[filaSeleccionada][j];
        }
    }

    // 4. Salida del Resultado
    printf("El valor m�ximo en la fila %d es: %d\n", filaSeleccionada, maximo);

    return 0;
}
