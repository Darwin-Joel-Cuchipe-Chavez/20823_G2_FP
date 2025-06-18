#include <stdio.h>

int main() {
    int vec[100];
    int num, i;

    printf("Ingresar la cantidad de componentes que desea calcular (menor o igual a 100): ");
    scanf("%d", &num);

    if (num <= 100) {
        for (i = 0; i < num; i++) {
            vec[i] = (i + 1) * (i + 1) + 3;
        }
    } else {
        printf("Lo siento, excedio el limite de 100\n");
        return 1;
    }

    printf("===============================================\n");
    printf("Los elementos del vector vec[i] son:\n");
    printf("vec[i] = ");
    for (i = 0; i < num; i++) {
        printf(" %d", vec[i]);
    }
    printf("\n");

    return 0;
}
