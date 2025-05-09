Algoritmo Problema1_7
	Escribir 'Desarrolle un programa que lea por teclado un número indeterminado de alturas y que deje de leer cuando se haya introducido a una negativa el programa debe calcular e imprimir la media el máximo el mínimo de la altura introducidas'
	Definir altura, resp, media, maxima_altura, minima_altura Como Real
	Definir divi Como Entero
	media <- media+altura
	maxima_altura = -1
	minima_altura = 99999999999
	Repetir
		Escribir 'Ingresar la altura'Sin Saltar
		Leer altura
		Si altura>=0 Entonces
			media <- media+altura
			divi <- divi+1
			Si altura>maxima_altura Entonces
				maxima_altura <- altura
			FinSi
			Si altura<minima_altura Entonces
				minima_altura <- altura
			FinSi
		SiNo
			Escribir 'No se ingreso una altura positiva'
		FinSi
	Hasta Que altura<0
	Si divi>0 Entonces
		resp <- TRUNC((media/divi)*100+0.5)/100
		Escribir 'La media de las alturas es ', resp
		Escribir 'La altura máxima ingresada es: ', maxima_altura
		Escribir 'La altura mínima ingresada es: ', minima_altura
	SiNo
		Escribir "No se ingreso una altura positiva"
	FinSi
FinAlgoritmo
