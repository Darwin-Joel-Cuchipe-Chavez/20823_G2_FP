#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cant, dias, horas, minutos, segundos;
    printf("Ingresar la cantidad que desee convertir a unidades de tiempo: \n");
    scanf("%i",&cant);
    dias = cant/86400;
    int resi = cant%86400;
    horas = resi/3600;
    resi = resi%3600;
    minutos = resi/60;
    resi = resi%60;
    segundos = resi;
    printf("La cantidad de %d representa: %d dias, %d horas, %d minutos, y %d segundos",cant,dias,horas,minutos,segundos);
    return 0;
}