#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont, divi;
    float num, suma, resp;
    suma = 0;
    cont = 0;
    divi = 0;
    while (cont<3)
    {
        printf("Ingresar un número:\n");
        scanf("%f",&num);
        if (num>0)
        {
            suma += num;
            divi++;
        }
        cont++;
    }
    resp = suma/divi;
    if (divi==0)
    {
        printf("NO se ingreso números positivos por lo que no se puede dividir para 0");
    }
    else
    {
        printf(" La media de los valores positivos ingresados es %.2f",resp);
    }
    return 0;
}
