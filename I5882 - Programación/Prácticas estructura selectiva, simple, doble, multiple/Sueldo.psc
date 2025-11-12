Algoritmo SUELD0
	Definir ANIOS, SUELDO como real
	Escribir "Introduzca años en la empresa: "
	Leer ANIOS
	Escribir "Introduzca Sueldo: $"
	Leer Sueldo
	Si ANIOS>10
		SUELDO=SUELDO*1.10
	SiNo
		Si ANIOS>5
			SUELDO=SUELDO*1.07
		SiNo
			Si ANIOS>3
				SUELDO=SUELDO*1.05
			SiNo
				SUELDO=SUELDO*1.03
			FinSi
		FinSi
	FinSi
	Escribir "Su nuevo sueldo es: " SUELDO
FinAlgoritmo
