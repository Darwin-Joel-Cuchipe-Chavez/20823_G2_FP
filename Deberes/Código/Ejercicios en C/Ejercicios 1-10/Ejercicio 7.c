#include <stdio.h>

int main()
{
    float altura, media, suma = 0, alt_maxima = -1, alt_minima = 9999999999;
    int divi = 0;
    printf("Ingresar la altura(ingrese una cantidad negativa para terminar):\n");
    scanf("%f",&altura);
    while (altura>=0)
    {
        if (altura>alt_maxima)
        {
            alt_maxima = altura;
        }
        if (altura<alt_minima)
        {
            alt_minima = altura;
        }
        suma += altura;
        divi++;
        printf("Ingresar la altura (ingrese una cantidad negativa para terminar):\n");
        scanf("%f",&altura);
    }
    if (divi>0)
    {
        media = suma/divi;
        printf("La media de alturas es %f, la altura maxima es %f y la altura minima es %f",media, alt_maxima,alt_minima);
    }
    else
    {
        printf("NO se ingreso valores positivos, por ende no hay division entre 0");
    }
    return 0;
}