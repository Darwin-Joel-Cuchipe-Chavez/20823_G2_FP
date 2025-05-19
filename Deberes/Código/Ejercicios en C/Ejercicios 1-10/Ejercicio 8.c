#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    float raiz = 0;
    printf("Ingresar el numero que desea calcular su raiz cuadrada> \n");
    scanf("%i",&num);
    if (num>0)
    {
        raiz = sqrt(num);
        printf("La raiz cuadrada de %d es: %.2f",num,raiz);
    }
    else
    {
        printf("NO es posible sacar la raiz cuadrada de un numero negativo");
    }
    return 0;
}
