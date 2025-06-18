#include <stdio.h>

float vec[];
float num, suma = 0;
int i, lim;
//void invector (float vec[], int n){
    //lim = 1;
//}

int main (){
    printf("INGRESAR UNA CANTIDAD QUE VA A SER EL TAMAÑO MAXIMO DEL VECTOR (MAXIMO 10): \n");
    scanf("%i",&lim);
    if (lim>0 && lim<11){
        for(int i=1; i<=lim; i++){
            printf("Ingresar un número para la posición %d:\n",i);
            scanf("%f",&num);
            vec[i] = num*num;
            suma = suma + vec[i];
            printf("El cuadrado del vector es: %.2f\n",suma);
        }
    }
    else{
        printf("ERROR, NO HAZ INGRESADO UNA CANTIDAD VALIDA :C");
    }
    return 0;
}
