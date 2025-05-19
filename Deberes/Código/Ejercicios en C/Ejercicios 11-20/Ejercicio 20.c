#include <stdio.h>

int main()
{
    float num,suma,promedio;
    int i;
    for (i = 1;i <=5;i++){
        printf("Ingresar la nota: \n");
        scanf("%f",&num);
        suma += num;
        promedio = suma/5;
    }
    printf("El promedio de los numeros ingresados es: %0.2f",promedio);
    return 0;
}
