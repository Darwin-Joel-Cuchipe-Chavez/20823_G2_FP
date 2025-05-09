Algoritmo Problema1_5
	Escribir 'Desarrolle un programa que lea por teclado un valor entero X e, interpretando este valor como el número de segundos que dura un evento, calcule y muestre por pantalla cuántos días, horas, minutos y segundo representa x'
	Definir x Como Entero; Definir x2,num_dias,num_horas,num_minutos,num_segundos Como Real
	Escribir 'Ingresar una cantidad a transformar en medidas del tiempo'Sin Saltar
	Leer x
	num_dias=TRUNC(x/86400)
	x2=x%86400
	num_horas=TRUNC((x2/3600)*100+0.5)/100
	x2=x2%3600
	num_minutos=TRUNC((x2/60)*100+0.5)/100
	x2=x2%60
	num_segundos=TRUNC((x2/60)*100+0.5)/100
	Escribir "La cantidad de ",x,", representa: ",num_dias," días,",num_horas," horas,",num_minutos," minutos y ",num_segundos," segundos"
FinAlgoritmo
