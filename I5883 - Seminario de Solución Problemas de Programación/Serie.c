/*
Juan Antonio Arroyo Santana - INNI (220792779)
5.- Realice un algoritmo que pida un número entero N al usuario  el cual corresponde a la cantidad de
números de la serie que se mostrarán y calcule el resultado de la siguiente serie: 2/1  +  4/3 +  6/5  + 8/7  + 10/9  +  12/11...
El resultado lo debe mostrar con decimales.*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int CANTIDAD,i;
    float A=2,B=1,X=0;
    printf("SERIE\n\n");
    printf("Ingrese la cantidad de n%cmeros que se mostrar%cn: ",163,160);
    scanf("%d",&CANTIDAD);
    for(i=1;i<=CANTIDAD;i++)
    {
        printf("%.0f/%.0f=%f\n",A,B,A/B);
        X=X+(A/B);
        A+=2;
        B+=2;
    }
    printf("\nEl resultado es: %f",X);
    return 0;
}
