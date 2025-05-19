#include <stdio.h>

int main()
{
    float num;
    printf("Ingresar un numero (ingrese una cantidad negativa para terminar):\n");
    scanf("%f",&num);
    while (num>=0)
    {
        printf("Ingresar la altura (ingrese una cantidad negativa para terminar):\n");
        scanf("%f",&num);
    }
    printf("Haz ingresado un valor negativo, Se finaliza el programa :)");
    return 0;
}
