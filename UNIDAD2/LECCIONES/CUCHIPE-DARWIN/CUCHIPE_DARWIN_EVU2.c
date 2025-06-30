#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int inicio = 0, fiin = 0, num_int = 0, num_usu = 0, validador = 0;
    int num_anterior = -1;
    srand(time(NULL));

    int matriz[10][3] = {0};

    for(int j = 0; j < 10; j++){
        for(int k = 0; k < 3; k++){
            matriz[j][k] = 0;
        }
    }

    printf(" ===== ADIVINA EL NUMERO ===== \n");
    printf("INGRESE EL INICIO DEL INTERVALO PARA GENERAR EL NUMERO SECRETO: \n");//RF1: Inicio del intervalo
    scanf("%i", &inicio);
    while(inicio < 0){
        printf("INICIO NO VALIDO, INGRESE NUEVAMENTE: \n");
        scanf("%i", &inicio);
    }

    printf("INGRESE EL FINAL DEL INTERVALO PARA GENERAR EL NUMERO SECRETO: \n");//RF1: Final del intervalo
    scanf("%i", &fiin);
    while(fiin < 0 || fiin <= inicio){
        printf("FINAL NO VALIDO, INGRESE NUEVAMENTE: \n");
        scanf("%i", &fiin);
    }

    int num_sec = inicio + rand() % (fiin - inicio + 1);

    printf("INGRESE EL NUMERO MAXIMO DE INTENTOS (cantidad maxima a ingresar 10): \n");//RF2: Numero de intentos
    scanf("%i", &num_int);
    while(num_int < 1 || num_int > 10){
        printf("NUMERO MAXIMO DE INTENTOS NO VALIDO (cantidad maxima a ingresar 10): \n");
        scanf("%i", &num_int);
    }

    printf(" ===== AHORA ES TU TURNO DE ADIVINAR =====\n");
    for (int i = 0; i < num_int; i++){
        printf("INTENTO N %i \n", i + 1);
        printf("INGRESE EL NUMERO QUE USTED CREA QUE ES EL SECRETO: \n");
        while(1){
            scanf("%i", &num_usu);
            if(num_usu == num_anterior){
                printf("NO PUEDE INGRESAR EL MISMO NUMERO QUE EN EL INTENTO ANTERIOR\n");//RF3: Comparar con el numero anterior
                printf("INGRESE NUEVAMENTE: \n");
                continue;
            }
            if(num_usu < inicio || num_usu > fiin){
                printf("EL NUMERO NO PERTENECE AL INTERVALO, INGRESE NUEVAMENTE: \n");//RF3: Validación de intervalo
                continue;
            }

            break;
        }
        num_anterior = num_usu;
        if(num_usu == num_sec){
            validador = 1;
        } else {
            validador = 0;
        }
        matriz[i][0] = i + 1;//RF4: Almacenar en la matriz
        matriz[i][1] = num_usu;//RF4: Almacenar en la matriz
        matriz[i][2] = validador;//RF4: Almacenar en la matriz
        if(validador == 1){
            printf("¡CORRECTO! HAS ADIVINADO EL NUMERO SECRETO.\n");
            break;
        }
    }

    printf(" ===== RESULTADOS =====\n");//RF5: Imprimir la matriz
    for(int j = 0; j < num_int; j++){
        if(matriz[j][0] != 0){
            printf("INTENTO %i: NUMERO %i -> %s\n",
                  matriz[j][0],
                  matriz[j][1],
                  matriz[j][2] ? "CORRECTO" : "INCORRECTO");
        }
    }

    return 0;
}
