#include <stdio.h>
#include <string.h>

int main()
{
    char contr [20];
    char vali[] = "PEPITOKUN19";
    printf("Ingresar la contraseña: \n");
    scanf("%s",contr);
    do{
        printf("Ingrese otra vez la contraseña: \n");
        scanf("%s",contr);
    }while (strcmp(contr, vali) != 0);
    printf("Acceso otorgado, gracias por validar su contraseña :)");
    return 0;
}
