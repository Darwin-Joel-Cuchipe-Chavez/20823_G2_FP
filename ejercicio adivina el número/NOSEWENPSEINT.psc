Algoritmo sin_titulo
	Escribir "ADIVINAR N�MERO"
	Escribir "============================================="
	com = AZAR(101)
	Escribir com
	Para i<-1 Hasta 5 Con Paso 1 Hacer
		Escribir "INGRESAR UN N�MERO:"
		Leer num
		Si num == com Entonces
			Escribir "FELICIDADES HAZ ADIVINADO EL N�MERO"
			Escribir ":)"
			i = 6
		SiNo
			Escribir "LO SIENTO, HAZ FALLADO :("
			Escribir "INTENTO ",i," DE 5"
			Escribir "============================================="
		FinSi
	FinPara
FinAlgoritmo
