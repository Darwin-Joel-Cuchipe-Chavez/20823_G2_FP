#include <stdio.h>

int main()
{
    int suma = 0, i;
    printf("Suma de los 10 primeros numero naturales\n");
    for (i = 1;i<=10;i++){
        suma += i;
    }
    printf("La suma de los 10 primeros numeros naturales es: %i",suma);
    return 0;
}
