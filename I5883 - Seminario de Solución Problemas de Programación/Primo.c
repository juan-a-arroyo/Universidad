#include <stdio.h>
#include <stdlib.h>
int main (){
    int NUMERO,FIN,i,j,CUENTA;
    printf("CALCULADORA DE N%cMEROS PRIMOS\n\nIngrese el inicio del rango: ",233);
    scanf("%d",&NUMERO);
    printf("\nIngrese el fin del rango: ");
    scanf("%d",&FIN);
    while(NUMERO>=FIN)
    {
        printf("\nIngrese un n%cmero de fin mayor al de inicio: ",163);
        scanf("%d",&FIN);
    }
    printf("\n");
    for(i=NUMERO;i<=FIN;i++){
        CUENTA=0;
        for(j=1;j<=NUMERO;j++){
            if(NUMERO%j==0)
                CUENTA++;
        }
    if (CUENTA==2)
        printf("%d, ",NUMERO);
    NUMERO++;
    }
    printf("\n");
    return 0;
}

