Algoritmo Problema1_6_2
	Escribir 'Desarrolle un programa que lea 3 números reales del teclado y escriba por pantalla la media aritmética únicamente de los números positivos leídos realiza el algoritmo en 2 versiones empleando una iteración con salida en cabeza y con salida en cola'
	Definir num, media, resul Como Real
	Definir cont, divi Como Entero
	Repetir
		Escribir 'Ingresar un número para sumar a la media aritmetica'Sin Saltar
		Leer num
		Si num>0 Entonces
			media <- media+num
			divi <- divi+1
		FinSi
		cont <- cont+1
	Hasta Que cont==3
	Si divi>0 Entonces
		resul <- TRUNC((media/divi)*100+0.5)/100
		Escribir 'La media aritmetica de los números positivos ingresados es :', resul
	SiNo
		Escribir 'No se ingreso ningun número positivo'
	FinSi
FinAlgoritmo
