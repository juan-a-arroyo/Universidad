/*
Juan Antonio Arroyo Santana - INNI
Práctica 6
Realice un programa que muestre al usuario el siguiente menú de opciones:

Elige la opción de lo que deseas comprar.

1.- Refresco
2.- Botana
3.- Agua
*/
#include <stdio.h>
#define REFRESCO 15
#define BOTANA 12
#define AGUA 10
int main()
{
    int COMPRA,MONTO,CAMBIO,CANTIDAD;
    printf("Elige la opcion que deseas comprar:\n\n");
    printf("1. Refresco $15\n2. Botana $12\n3. Agua $10\n");
    scanf("%i",&COMPRA);
    if(COMPRA<1||COMPRA>3)
        printf("Compra invalida");
    if(COMPRA>0&&COMPRA<4)
    {
        printf("Seleccione la cantidad a pagar: ");
        scanf("%i",&MONTO);
    }
    if(COMPRA==1)
    {
        if(MONTO>REFRESCO)
        {
            CAMBIO=MONTO-REFRESCO;
            printf("Su cambio es de: $%i\n",CAMBIO);
            CANTIDAD=CAMBIO;
        }
        if(MONTO<REFRESCO)
        printf("Monto insuficiente, falta/n $%i",REFRESCO-MONTO);
    }
    if(COMPRA==2&&MONTO<101)
    {
        if(MONTO>BOTANA)
        {
            CAMBIO=MONTO-BOTANA;
            printf("Su cambio es de: $%i\n",CAMBIO);
            CANTIDAD=CAMBIO;
        }
        if(MONTO<BOTANA)
        printf("Monto insuficiente, falta/n $%i",BOTANA-MONTO);
    }
    if(COMPRA==3&&MONTO<101)
    {
        if(MONTO>AGUA)
        {
            CAMBIO=MONTO-AGUA;
            printf("Su cambio es de: $%i\n",CAMBIO);
            CANTIDAD=CAMBIO;
        }
        if(MONTO<AGUA)
        printf("Monto insuficiente, falta/n $%i",AGUA-MONTO);
    }
    if(COMPRA>0&&COMPRA<4)
        if(MONTO>REFRESCO||MONTO>BOTANA||MONTO>AGUA)
        {
            CAMBIO = CAMBIO/100;
            printf("\n%i Billete/s de $100",CAMBIO);
            CANTIDAD=CANTIDAD%100;

            CAMBIO = CANTIDAD/50;
            printf("\n%i Billete/s de $50",CAMBIO);
            CANTIDAD=CANTIDAD%50;

            CAMBIO = CANTIDAD/20;
            printf("\n%i Billete/s de $20",CAMBIO);
            CANTIDAD=CANTIDAD%20;

            CAMBIO = CANTIDAD/10;
            printf("\n%i Moneda/s de $10",CAMBIO);
            CANTIDAD=CANTIDAD%10;

            CAMBIO = CANTIDAD/5;
            printf("\n%i Moneda/s de $5",CAMBIO);
            CANTIDAD=CANTIDAD%5;

            CAMBIO = CANTIDAD/2;
            printf("\n%i Moneda/s de $2",CAMBIO);
            CANTIDAD=CANTIDAD%2;

            CAMBIO = CANTIDAD/1;
            printf("\n%i Moneda/s de $1",CAMBIO);
            CANTIDAD=CANTIDAD%1;
        }
    return 0;
}
