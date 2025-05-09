Algoritmo Problema1_2
	Escribir 'Desarrolle un programa que lea un número real X y escriba por pantalla |X|³'
	Definir X,val_abs,resp Como Entero
	Escribir 'Ingresar el número que desea calcular su valor absoluto seguido por su cubo:'Sin Saltar
	Leer X
	Si X<0 Entonces
		val_abs <- X*(-1)
		resp <- val_abs^3
		Escribir 'El valor absoluto de ', X, ' es ',val_abs," y elevado al cubo es: ", resp
	SiNo
		resp <- X^3
		Escribir 'El valor absoluto de ', X, ' es ',X," y elevado al cubo es: ", resp
	FinSi
FinAlgoritmo
