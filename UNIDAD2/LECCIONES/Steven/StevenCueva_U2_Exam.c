#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

// RF4: estructura para registrar intentos
struct Intento {
    int num;
    int valor;
    int resultado; // 0=bajo, 1=alto, 2=correcto
};

int main() {
    int min, max, secreto, maxIntentos, intento, usados[1000] = {0};
    struct Intento intentos[MAX_INTENTOS];

    // RF1: rango dinámico
    printf("Rango mínimo: "); scanf("%d", &min);
    printf("Rango máximo: "); scanf("%d", &max);
    if (min >= max) return printf("Error de rango.\n"), 1;

    srand(time(NULL));
    secreto = min + rand() % (max - min + 1);

    // RF2: número de intentos
    do {
        printf("Intentos (1-10): ");
        scanf("%d", &maxIntentos);
    } while (maxIntentos < 1 || maxIntentos > MAX_INTENTOS);

    int i = 0;
    while (i < maxIntentos) {
        printf("Intento %d: ", i + 1);
        scanf("%d", &intento);

        // RF3: validar rango y duplicado
        if (intento < min || intento > max || usados[intento]) {
            printf("Inválido o repetido.\n");
            continue;
        }
        usados[intento] = 1;

        // RF4: guardar intento
        intentos[i].num = i + 1;
        intentos[i].valor = intento;

        if (intento < secreto) {
            intentos[i].resultado = 0; printf("Muy bajo.\n");
        } else if (intento > secreto) {
            intentos[i].resultado = 1; printf("Muy alto.\n");
        } else {
            intentos[i].resultado = 2; printf("¡Correcto!\n"); i++; break;
        }
        i++;
    }

    // RF5: resumen
    printf("\nResumen:\n");
    printf("N°\tValor\tResultado\n");
    for (int j = 0; j < i; j++) {
        printf("%d\t%d\t", intentos[j].num, intentos[j].valor);
        if (intentos[j].resultado == 0) printf("Muy bajo\n");
        else if (intentos[j].resultado == 1) printf("Muy alto\n");
        else printf("Correcto\n");
    }

    if (intentos[i - 1].resultado != 2)
        printf("No adivinaste. El número era: %d\n", secreto);

    return 0;
}

