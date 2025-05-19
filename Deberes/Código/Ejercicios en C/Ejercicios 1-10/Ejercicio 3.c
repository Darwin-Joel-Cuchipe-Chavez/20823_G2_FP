#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    printf("Ingrese dos números separados por un espacio:\n");
    scanf("%i %i",&num1,&num2);
    if (num2 == 0) {
    printf("Error: No se puede dividir por cero.\n");
} else if ((num1 % num2) == 0) {
    printf("El número %d si es divisible para %d", num1, num2);
} else {
    printf("El número %d NO es divisible para %d", num1, num2);
}return 0;
}
