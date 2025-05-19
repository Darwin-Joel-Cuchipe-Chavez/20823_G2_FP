#include <stdio.h>

int main()
{
    float nota;
    do{
        printf("Ingresar una nota entre 0 y 10 :\n");
        scanf("%f",&nota);
        if (nota>=0 && nota<=10){
            printf("%2.f esta entre 0 y 10\n",nota);
        }
        else{
            printf("%2.f no esta entre 0 y 10\n",nota);
        }
    }while (nota>-1 && nota<11);
    return 0;
}
