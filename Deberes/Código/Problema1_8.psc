Algoritmo Problema1_8
	Escribir 'Desarrolle un programa que calculé la raíz cuadrada entera por defecto de un número N positivo dado, que se define como el mayor número entero R > 0, tal que R² <= N"
	Definir num Como Entero
	Definir raiiz Como Real
	Escribir 'Ingresar un número del que desea obtener su raiz cuadrada'Sin Saltar
	Leer num
	Si num<0 Entonces
		Escribir "No existe la raiz cuadrada de ",num
	SiNo
		raiiz=TRUNC(raiz(num)*100+0.5)/100
		Escribir "La raiz cuadrada de ",num," es ",raiiz
	FinSi
FinAlgoritmo