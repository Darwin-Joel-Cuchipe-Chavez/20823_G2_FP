Algoritmo sin_titulo
	Escribir "ADIVINAR NÚMERO"
	Escribir "============================================="
	com = AZAR(101)
	Escribir com
	Para i<-1 Hasta 5 Con Paso 1 Hacer
		Escribir "INGRESAR UN NÚMERO:"
		Leer num
		Si num == com Entonces
			Escribir "FELICIDADES HAZ ADIVINADO EL NÚMERO"
			Escribir ":)"
			i = 6
		SiNo
			Escribir "LO SIENTO, HAZ FALLADO :("
			Escribir "INTENTO ",i," DE 5"
			Escribir "============================================="
		FinSi
	FinPara
FinAlgoritmo
