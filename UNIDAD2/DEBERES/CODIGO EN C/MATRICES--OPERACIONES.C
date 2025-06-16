#include <stdio.h>

void pedirMatriz(int n, int matriz[n][n]) {
    printf("Introduce los elementos de la matriz %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int n, int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumar(int n, int a[n][n], int b[n][n], int res[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void restar(int n, int a[n][n], int b[n][n], int res[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplicar(int n, int a[n][n], int b[n][n], int res[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void potenciar(int n, int matriz[n][n], int potencia, int res[n][n]) {
    // Copiar matriz en resultado como base
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = matriz[i][j];
        }
    }
    int temp[n][n];

    // Multiplicar matriz por sí misma potencia-1 veces
    for (int p = 1; p < potencia; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    temp[i][j] += res[i][k] * matriz[k][j];
                }
            }
        }
        // Copiar temp a res
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = temp[i][j];
            }
        }
    }
}

int pedirTamanio() {
    int n;
    do {
        printf("Introduce el tamaño de la matriz (entero positivo): ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Error: el tamaño debe ser un entero positivo.\n");
        }
    } while (n <= 0);
    return n;
}

int main() {
    int opcion, potencia;

    do {
        printf("\nMENU\n");
        printf("1. Suma de matrices\n");
        printf("2. Resta de matrices\n");
        printf("3. Multiplicacion de matrices\n");
        printf("4. Potenciacion de matriz\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        if (opcion >=1 && opcion <=4) {
            int n = pedirTamanio();
            int matrizA[n][n], matrizB[n][n], resultado[n][n];

            switch (opcion) {
                case 1:
                    printf("Introduce matriz A:\n");
                    pedirMatriz(n, matrizA);
                    printf("Introduce matriz B:\n");
                    pedirMatriz(n, matrizB);
                    sumar(n, matrizA, matrizB, resultado);
                    printf("Resultado de la suma:\n");
                    mostrarMatriz(n, resultado);
                    break;
                case 2:
                    printf("Introduce matriz A:\n");
                    pedirMatriz(n, matrizA);
                    printf("Introduce matriz B:\n");
                    pedirMatriz(n, matrizB);
                    restar(n, matrizA, matrizB, resultado);
                    printf("Resultado de la resta:\n");
                    mostrarMatriz(n, resultado);
                    break;
                case 3:
                    printf("Introduce matriz A:\n");
                    pedirMatriz(n, matrizA);
                    printf("Introduce matriz B:\n");
                    pedirMatriz(n, matrizB);
                    multiplicar(n, matrizA, matrizB, resultado);
                    printf("Resultado de la multiplicacion:\n");
                    mostrarMatriz(n, resultado);
                    break;
                case 4:
                    printf("Introduce matriz A:\n");
                    pedirMatriz(n, matrizA);
                    do {
                        printf("Introduce la potencia (entero positivo): ");
                        scanf("%d", &potencia);
                        if (potencia < 1) {
                            printf("Error: la potencia debe ser al menos 1.\n");
                        }
                    } while (potencia < 1);
                    potenciar(n, matrizA, potencia, resultado);
                    printf("Resultado de la potencia %d:\n", potencia);
                    mostrarMatriz(n, resultado);
                    break;
            }
        } else if (opcion == 5) {
            printf("Saliendo...\n");
            break;
        } else {
            printf("Opcion invalida, intente de nuevo.\n");
        }
    } while (1);

    return 0;
}

