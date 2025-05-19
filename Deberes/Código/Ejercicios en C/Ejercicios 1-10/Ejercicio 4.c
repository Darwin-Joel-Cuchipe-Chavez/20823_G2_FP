#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("Ingrese un nC:mero:\n");
	scanf("%i",&num);
	if (num>0 && num<10)
	{
		printf("El nC:mero %d pertenece al intervalo entre [0,10]",num);
	}
	else {
		printf("El nC:mero %d NO pertenece al intervalo entre [0,10]",num);
	}
	return 0;
}
