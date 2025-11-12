Algoritmo Credito
	Definir NUM_CTA,SALDO_INICIAL,SALDO_FINAL,CREDITOS,LIMITE Como Entero
	Escribir "introduzca el número de cuenta del cliente: "
	Leer NUM_CTA
	Escribir "Introduzca el saldo inicial del cliente: "
	Leer SALDO_INICIAL
	Escribir "Introduzca los creditos aplicados a la cuenta del cliente: "
	Leer CREDITOS
	Escribir "Introduzca el límite de crédito del cliente: "
	Leer LIMITE
	SALDO_FINAL=SALDO_INICIAL+CREDITOS
	Si SALDO_FINAL>LIMITE
		Escribir "El número de cuenta del cliente es: " NUM_CTA
		Escribir "El límite de crédito del cliente es: " LIMITE
		Escribir "El nuevo saldo del cliente es: " SALDO_FINAL
		Escribir "LÍMITE DE CRÉDITO EXCEDIDO"
	SiNo
		Escribir "El Nuevo saldo del cliente es: " SALDO_FINAL
	FinSi
FinAlgoritmo
