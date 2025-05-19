#include <stdio.h>

int main()
{
    float num;
    printf("Ingresar un numero:\n");
    scanf("%f",&num);
    if (num>0){
        printf("%f es positivo",num);
    }
    else{
        if (num == 0){
            printf("%.0f es cero",num);
        }
        else{
            printf("%f es negativo",num);
        }
    }
    return 0;
}
