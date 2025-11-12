/*
Juan Antonio Arroyo Santana - INNI (220792779)
2.- Realice un algoritmo que indique si un número pedido al usuario es primo o no lo es
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int NUMERO,CUENTA=1,DIVISORES=0;
    printf("PROGRAMA QUE EVAL%cA SI UN N%cMERO ES PRIMO\n\n",233,233);
    printf("Ingrese el n%cmero a evaluar: ",163);
    scanf("%d",&NUMERO);
    do{
        if(NUMERO%CUENTA==0)
            DIVISORES++;
        CUENTA++;
    }while(CUENTA<=NUMERO);
    if(DIVISORES==2)
        printf("\n%d es un n%cmero primo\n",NUMERO,163);
    else
        printf("\n%d NO es un n%cmero primo\n",NUMERO,163);
        return 0;
}
