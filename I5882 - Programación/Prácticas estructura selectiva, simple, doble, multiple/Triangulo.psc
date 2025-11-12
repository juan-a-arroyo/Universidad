Algoritmo Triangulo
	Definir a,b,c Como Entero
	Escribir "Digite lados de un triángulo"
	Leer a,b,c
	si (a+b)>c y (a+c)>b y (b+c)>a
		si a=b o a=c o b=c
			Si a<>b o a<>c o b<>c
				escribir "Es un triángulo Isóceles"
			FinSi
			Si a=b y a=c
				escribir "Es un triángulo Equilátero"
			FinSi
		SiNo
			escribir "Es un triángulo Escaleno"
		FinSi
	SiNo
		escribir "No es un triángulo"
	FinSi
	
FinAlgoritmo

