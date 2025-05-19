#include <stdio.h>

int main()
{
    printf("EJERCICIO 1.1\n");
    float num1, num2, respuesta;
    printf("Introduzca 2 números reales:");
    scanf("%f %f",&num1,&num2);
    respuesta = (num1+num2)/2;
    printf("La media de %f y %f es: %f\n", num1, num2, respuesta);

    return 0;
}