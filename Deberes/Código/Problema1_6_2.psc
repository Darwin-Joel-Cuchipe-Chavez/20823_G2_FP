Algoritmo Problema1_6_2
	Escribir 'Desarrolle un programa que lea 3 n�meros reales del teclado y escriba por pantalla la media aritm�tica �nicamente de los n�meros positivos le�dos realiza el algoritmo en 2 versiones empleando una iteraci�n con salida en cabeza y con salida en cola'
	Definir num, media, resul Como Real
	Definir cont, divi Como Entero
	Repetir
		Escribir 'Ingresar un n�mero para sumar a la media aritmetica'Sin Saltar
		Leer num
		Si num>0 Entonces
			media <- media+num
			divi <- divi+1
		FinSi
		cont <- cont+1
	Hasta Que cont==3
	Si divi>0 Entonces
		resul <- TRUNC((media/divi)*100+0.5)/100
		Escribir 'La media aritmetica de los n�meros positivos ingresados es :', resul
	SiNo
		Escribir 'No se ingreso ningun n�mero positivo'
	FinSi
FinAlgoritmo
