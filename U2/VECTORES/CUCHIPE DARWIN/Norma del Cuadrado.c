#include <stdio.h>
#define MAX 10

float vec[];
float num, suma;
int i;
void invector (float vec[], int n){
    for(int i=1; i<=MAX; i++){
        printf("Ingresar un número para la posición %d:",i);
        scanf("%f",&num);
        vec[i] = num*num;
        suma = suma + vec[i];
        }
    printf("El cuadrado del vector es: %f",suma);
}

int main (){
    invector(vec,MAX);
    return 0;
}
