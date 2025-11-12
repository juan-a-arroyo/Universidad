#include <stdio.h>
int main (){
    int NUM_CTA,SALDO_INICIAL,SALDO_FINAL,CREDITOS,LIMITE;
    printf("Introduzca el n%cmero de cuenta del cliente: ",163);
	scanf("%d",&NUM_CTA);
	printf("Introduzca el saldo inicial del cliente: ");
	scanf("%d",&SALDO_INICIAL);
	printf("Introduzca los cr%cditos aplicados a la cuenta del cliente: ",130);
    scanf("%d",&CREDITOS);
	printf("Introduzca el l%cmite de cr%cdito del cliente: ",161,130);
	scanf("%d",&LIMITE);
	SALDO_FINAL=SALDO_INICIAL+CREDITOS;
	if(SALDO_FINAL>LIMITE)
    {
		printf("\nEl n%cmero de cuenta del cliente es: %d",163,NUM_CTA);
		printf("\nEl l%cmite de cr%cdito del cliente es: %d",161,130,LIMITE);
		printf("\nEl nuevo saldo del cliente es: %d",SALDO_FINAL);
		printf("\nL%cMITE DE CR%cDITO EXCEDIDO",214,144);
    }
    else
		printf("\nEl Nuevo saldo del cliente es: %d",SALDO_FINAL);
    return 0;
}
