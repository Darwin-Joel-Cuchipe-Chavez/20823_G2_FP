#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int num, valabs, poten;
	printf("Ingrear el número que desee realizar la oprración:\n");
	scanf("%i",&num);
	valabs = abs(num);
	poten = pow(valabs,3);
	printf("El valor absoluto de %d es %d, y elevado al cubo es %d",num, valabs, poten);
	return 0;
}