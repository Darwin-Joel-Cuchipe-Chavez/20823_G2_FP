#include <stdio.h>

int main()
{
    int inicio, final, i, j, cont, divi;
    printf("Ingresar el inicio del intervalo y el final separado por un espacio: \n");
    scanf("%i %i",&inicio,&final);
    for (i = inicio; i <= final; i++)
    {
        cont = 0;
        for (j = 1; j <= i; j++)
        {
            divi = i % j;
            if (divi == 0)
            {
                cont++;
            }
        }
        if (cont == 2)
        {
            printf("%i es un numero primo:\n",i);
        }
    }
    return 0;
}
