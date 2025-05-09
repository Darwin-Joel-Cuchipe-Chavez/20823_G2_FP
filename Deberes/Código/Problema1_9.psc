Algoritmo Ejercicio1_9
	Escribir 'Desarrolle un programa que lea por un número entero por teclado e imprima en pantalla si es un número primo o no'
	Definir I, A, divi, val, inicio, fiin Como Entero
	Escribir 'Ingresar el inicio del intervalo'Sin Saltar
	Leer inicio
	Escribir 'Ingresar el final del intervalo'Sin Saltar
	Leer fiin
	Para A<-inicio+1 Hasta fiin Con Paso 1 Hacer
		val = 0
		Para I<-1 Hasta A Con Paso 1 Hacer
			divi <- A MOD I
			Si divi=0 Entonces
				val <- val+1
			FinSi
		FinPara
		Si val=2 Entonces
			Escribir A, ' Es un número primo'
		FinSi
	FinPara
FinAlgoritmo
