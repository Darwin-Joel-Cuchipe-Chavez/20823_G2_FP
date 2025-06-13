#include <stdio.h>

int main (){
	int i, j , num_ele, fila, columna, fila_bus, ele_may, n1, n2;
	printf("INGRESAR UN VALOR PARA LA CANTIDAD DE FILAS DE LA MATRIZ: ");
	scanf("%i",&fila);
	printf("INGRESAR UN VALOR PARA LA CANTIDAD DE COLUMNAS DE LA MATRIZ: ");
	scanf("%i",&columna);
	int matriz[fila][columna];
	for (int i = 0; i <fila; i++){
		for (int j = 0; j< columna; j++){
			printf("INGRESAR UN VALOR PARA LA POSICIÓN [%i][%i] DE LA MATRIZ: ",i,j);
			scanf("%i",&num_ele);
			matriz[i][j] = num_ele;
		}
	}
	printf("INGRESAR UN VALOR PARA BUSCAR LA FILA DE LA MATRIZ: ");
	scanf("%i",&fila_bus);
	if (fila_bus >= fila || fila_bus < 0) {
        printf("Error: La fila ingresada no existe en la matriz.\n");
        return 1;
	}
	ele_may = matriz[fila_bus][0];
    for (int j = 1; j < columna; j++) {
        if (matriz[fila_bus][j] > ele_may) {
            ele_may = matriz[fila_bus][j];
        }
    }
	printf("EL NUMEROMAS GRANDE DE LA FILA [%i] ES: %i",fila_bus,ele_may);
	return 0;
}
