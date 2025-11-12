Algoritmo Días
	definir DIA,MES,ANIO,DIA_N,MES_N,ANIO_N,DIAS,MESES,ANIOS,DIAS_TOTALES como entero
	escribir "Introduzca fecha Actual (dd/mm/aaaa): "
	leer DIA, MES, ANIO
	Si DIA>=1 y MES>=1 y (DIA<=31 o ((MES=4 o MES=6 o MES=9 o MES=11) y DIA<=30) o (MES=2 y DIA<=28))
		escribir "Introduzca fecha de nacimiento (dd/mm/aaaa): "
		leer DIA_N, MES_N, ANIO_N
		Si DIA_N>=1 y MES_N>=1 y (DIA_N<=31 o ((MES_N=4 o MES_N=6 o MES_N=9 o MES_N=11) y DIA_N<=30) o (MES_N=2 y DIA_N<=28))
			Si ANIO>ANIO_N o ANIO=ANIO_N y MES=MES_N y DIA>=DIA_N o ANIO=ANIO_N y MES>MES_N
				ANIOS=ANIO-ANIO_N
				MESES=MES-MES_N
				DIAS=DIA-DIA_N
				si MESES<0
					ANIOS=ANIOS-1
					MESES=12+(MESES)
				FinSi
				Si DIAS<0
					MESES=MESES-1
					Segun MESES hacer
						1: DIAS=DIAS+31
						2: DIAS=DIAS+28
						3: DIAS=DIAS+31
						4: DIAS=DIAS+30
						5: DIAS=DIAS+31
						6: DIAS=DIAS+30
						7: DIAS=DIAS+31
						8: DIAS=DIAS+31
						9: DIAS=DIAS+30
						10: DIAS=DIAS+31
						11: DIAS=DIAS+30	
						12: DIAS=DIAS+31					
					FinSegun
				FinSi
				escribir "Usted tiene " ANIOS " Años " MESES " Meses y "  DIAS " Días "
			SiNo
				escribir "Aún no has nacido"
			FinSi
		SiNo
			Escribir "Fecha de Nacimiento Inválida"
		FinSI
	SiNo
		escribir "Fecha actual inválida"
	FinSI
FinAlgoritmo
