Algoritmo Problema1_8
	Escribir 'Desarrolle un programa que calcul� la ra�z cuadrada entera por defecto de un n�mero N positivo dado, que se define como el mayor n�mero entero R > 0, tal que R� <= N"
	Definir num Como Entero
	Definir raiiz Como Real
	Escribir 'Ingresar un n�mero del que desea obtener su raiz cuadrada'Sin Saltar
	Leer num
	Si num<0 Entonces
		Escribir "No existe la raiz cuadrada de ",num
	SiNo
		raiiz=TRUNC(raiz(num)*100+0.5)/100
		Escribir "La raiz cuadrada de ",num," es ",raiiz
	FinSi
FinAlgoritmo