#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

int main() {
    int min, max, intentos, secreto, num, usado[MAX_INTENTOS], resultado[MAX_INTENTOS], i = 0, rep;

    srand(time(NULL));

    // RF01- El usuario definira el rango min y max
    printf("Rango mínimo: "); scanf("%d", &min);
    printf("Rango máximo: "); scanf("%d", &max);
    if (min >= max) { printf("Rango inválido.\n"); return 1; }

    secreto = rand() % (max - min + 1) + min;

    // RF02- El usuario definira max intentos
    printf("Intentos (máx 10): "); scanf("%d", &intentos);
    if (intentos > MAX_INTENTOS) intentos = MAX_INTENTOS;

    while (i < intentos) {
        printf("Intento %d: ", i + 1);
        scanf("%d", &num);

        // RF03 - El programa validara intentos dentro del rago
        if (num < min || num > max) { printf("Fuera de rango.\n"); continue; }
        rep = 0;
        for (int j = 0; j < i; j++) if (usado[j] == num) rep = 1;
        if (rep) { printf("Número repetido.\n"); continue; }

        // RF04 - Registro de intentos en la matriz
        usado[i] = num;
        if (num < secreto) resultado[i] = 0;
        else if (num > secreto) resultado[i] = 1;
        else { resultado[i] = 2; break; }
        i++;
    }

    // RF05 - Resumen
    printf("\nResumen:\nIntento\tValor\tResultado\n");
    for (int j = 0; j <= i; j++) {
        printf("%d\t%d\t", j + 1, usado[j]);
        if (resultado[j] == 0) printf("Bajo\n");
        else if (resultado[j] == 1) printf("Alto\n");
        else printf("Correcto\n");
    }

    if (resultado[i] != 2) printf("\nNo adivinaste. Secreto: %d\n", secreto);
    else printf("\n¡Correcto! Adivinaste el número.\n");

    return 0;
}
