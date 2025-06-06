#include <stdio.h>

int main() {
    int matriz[10][10];
    int f, c;
    int suma = 0;
    int num_jug;
    printf(" ===================================== \n");
    printf("      ----- MATRIZ 10x10 -----\n");
    printf(" ===================================== \n");
    for (f = 0; f < 10; f++) {
        for (c = 0; c < 10; c++) {
            printf(" ELEMENTO DE LA FILA [%d] COLUMNA [%d]: ", f + 1, c + 1);
            scanf("%d", &matriz[f][c]);
            suma += matriz[f][c];
        }
    }
    printf(" ===========================================\n");
    printf(" TURNO DEL JUGADOR \n");
    printf(" ========================================== \n");
    printf(" INTENTA ADIVINAR LA SUMA DE LOS ELEMENTOS INGRESADOS \n");
    printf(" INGRESA UN VALOR: \n");
    scanf("%d", &num_jug);
    if (num_jug == suma) {
        printf(" ========================================== \n");
        printf(" ----- FELICIDADES ----- \n");
        printf(" HAZ ACERTADO :) \n");
        printf(" =========================================== \n");
    } else {
        printf(" ========================================== \n");
        printf(" ----- NO HAZ ACERTADO ----- \n");
        printf(" LA RESPUESTA CORRECTA ES: %d\n", suma);
        printf(" =========================================== \n");
    }
    return 0;
}
