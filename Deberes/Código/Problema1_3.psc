Algoritmo Problema1_3
    Escribir "Desarrolle un programa que lea 2 n�meros enteros por teclado y determine si el primero de ellos es divisible por el segundo. Se mostrar� por pantalla el resultado"
    Definir num_1, num_2 Como Entero
    Escribir "Ingresar el primer n�mero:" Sin Saltar
    Leer num_1
    Escribir "Ingresar el segundo n�mero:" Sin Saltar
    Leer num_2
    Si num_2 = 0 Entonces
        Escribir "No es posible que 0 sea el segundo n�mero"
    Sino
        Si (num_1 % num_2) = 0 Entonces
            Escribir "El ", num_1, " es divisible por ", num_2, " y su resultado de la divisi�n es ", num_1 / num_2
        Sino
            Escribir "El ", num_1, " NO es divisible por ", num_2
        FinSi
    FinSi
FinAlgoritmo