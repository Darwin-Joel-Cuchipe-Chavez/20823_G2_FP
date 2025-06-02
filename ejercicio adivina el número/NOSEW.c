#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int main (){
    int num, com;
    srand(time(NULL));
    com = rand()%100;
    for (int i=1;i<=5;i++){
        printf("INGRESAR UN NÚMERO: ");
        scanf("%i",&num);
        if (num == com){
            printf("FELICIDADES, HAZ ACERTADO :)");
            break;
        }
        else{
            printf("LO SIENTO, HAZ FALLADO :(\n");
            printf("INTENTO %d DE 5\n",i);
            printf("=============================\n");
        }
    }
    return 0;
}
