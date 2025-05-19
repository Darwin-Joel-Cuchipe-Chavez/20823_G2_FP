#include <stdio.h>

int main()
{
    int edad;
    printf("Ingresar la edad a validar:\n");
    scanf("%i",&edad);
    if (edad<18 && edad >=0){
        printf("Es menor de edad :(");
    }
    else{
            if (edad<+99 && edad>=18){
            printf("Es mayor de edad :)");
            }
            else{
                printf("Es imposible :0");
            }
        }
    return 0;
}
