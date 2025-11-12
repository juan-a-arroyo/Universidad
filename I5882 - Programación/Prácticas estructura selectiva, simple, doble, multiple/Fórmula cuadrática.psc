Algoritmo Ecuaciones_Cuadráticas
	Definir a,b,c,b2,SOLUCION_1,SOLUCION_2,DISCRIMINANTE Como Real
	Escribir 'CALCULADORA DE ECUACIONES CUADRATICAS'
	Escribir 'Inserte valores a, b y c: '
	Leer a,b,c
	Si a<>0 Entonces
		Escribir 'Es una Ecuación cuadrática'
		Escribir 'Su ecuación es: ',a,'x^2 + ',b,'x + ',c,' =0 '
		b2 <- b^2
		Si b2-(4*a*c)>=0 Entonces
			DISCRIMINANTE <- rc(b2-(4*a*c))
			Escribir 'La discriminante es: ',DISCRIMINANTE
			Si DISCRIMINANTE>=1 Entonces
				SOLUCION_1 <- (-(b)+(DISCRIMINANTE))/(2*a)
				SOLUCION_2 <- (-(b)-(DISCRIMINANTE))/(2*a)
				Escribir 'Tiene dos soluciones'
				Escribir 'La solucion 1 es: ',SOLUCION_1
				Escribir 'La solucion 2 es: ',SOLUCION_2
			SiNo
				SOLUCION_1 <- (-(b))/(2*a)
				Escribir 'Tiene una sola solucion'
				Escribir 'La solución es: ',SOLUCION_1
			FinSi
		SiNo
			Escribir 'No tiene solucion (La Raíz es Compleja)'
		FinSi
	SiNo
		Escribir 'No es una Ecuación cuadrática'
	FinSi
FinAlgoritmo


