#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10



int main() {
    int rangoMin, rangoMax, intentosMax, numeroSecreto;
    int registro[MAX_INTENTOS][3]; // [intento][valor ingresado, resultado, estado]
    int intentoActual = 0, adivinado = 0;

    srand(time(NULL));

    // RF01
    printf("Ingrese el rango mínimo: ");
    scanf("%d", &rangoMin);
    printf("Ingrese el rango máximo: ");
    scanf("%d", &rangoMax);

    // Validación de rango
    if (rangoMin >= rangoMax) {
        printf("Rango inválido. Asegúrese de que mínimo < máximo.\n");
        return 1;
    }

    // RF02
    printf("Ingrese el número máximo de intentos (máximo %d): ", MAX_INTENTOS);
    scanf("%d", &intentosMax);

    if (intentosMax < 1 || intentosMax > MAX_INTENTOS) {
        printf("Número de intentos inválido.\n");
        return 1;
    }

    numeroSecreto = (rand() % (rangoMax - rangoMin + 1)) + rangoMin;

    printf("¡El número secreto ha sido generado! Intenta adivinarlo.\n");

    while (intentoActual < intentosMax && !adivinado) {
        int valor, repetido = 0;

        printf("Intento %d/%d - Ingrese un número: ", intentoActual + 1, intentosMax);
        scanf("%d", &valor);

        // RF03: Validación de rango
        if (valor < rangoMin || valor > rangoMax) {
            printf("El número está fuera del rango. Intente nuevamente.\n");
            continue;
        }

        // Validación de duplicados
        for (int i = 0; i < intentoActual; i++) {
            if (registro[i][0] == valor) {
                repetido = 1;
                break;
            }
        }
        if (repetido) {
            printf("Ya intentó este número. Intente nuevamente.\n");
            continue;
        }

        // RF04: Registro del intento
        registro[intentoActual][0] = valor;
        if (valor < numeroSecreto) {
            registro[intentoActual][1] = 0; // Bajo
        } else if (valor > numeroSecreto) {
            registro[intentoActual][1] = 1; // Alto
        } else {
            registro[intentoActual][1] = 2; // Correcto
            adivinado = 1;
        }

        intentoActual++;
    }

    // RF05: Visualización de resumen
    printf("\nResumen de intentos:\n");
    printf("Intento\tValor\tResultado\n");
    for (int i = 0; i < intentoActual; i++) {
        printf("%d\t%d\t%s\n", i + 1, registro[i][0],
               registro[i][1] == 0 ? "Bajo" :
               registro[i][1] == 1 ? "Alto" : "Correcto");
    }

    if (adivinado) {
        printf("¡Felicidades! Adivinaste el número secreto: %d\n", numeroSecreto);
    } else {
        printf("Lo siento, no lograste adivinar el número secreto: %d\n", numeroSecreto);
    }

    return 0;
}
