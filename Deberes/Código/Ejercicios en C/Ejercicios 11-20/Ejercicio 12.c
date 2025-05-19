#include <stdio.h>

int main()
{
    int num, val;
    printf("Ingresar el numero para validar; \n");
    scanf("%i",&num);
    val = num%2;
    if (val == 0){
        printf("%i es par",num);
    }
    else{
        printf("%i es impar",num);
    }
    return 0;
}
