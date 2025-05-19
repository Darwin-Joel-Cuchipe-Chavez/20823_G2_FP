#include <stdio.h>
#include <stdio.h>

int main()
{
    float num,suma = 0, media;
    int divi = 0, cont = 1;
    do
    {
        printf("Ingresar un número: \n");
        scanf("%f",&num);
        if (num>=0)
        {
            suma += num;
            divi++;
        }
        cont++;
    }while (cont<=3);
    media = suma/divi;
    if (divi == 0)
    {
        printf("NO se ingreso númers positivos, por lo que no se puede dividir para 0");
    }
    else
        printf("La media de los números positivos ingresados es:%.2f",media);
    return 0;
}