/*
Juan Antonio Arroyo Santana - INNI
Práctica 3
Realice un programa que convierta pesos a dollar norteamericano,
dollar canadiense, euro, libra, yen y yuan, el usuario puede elegir a qué moneda convertirse.
*/
#include <stdio.h>
#define USD 21.91
#define CAD 16.47
#define EUR 25.70
#define GBP 28.20
#define JPY 0.21
#define CNY 3.23
    //MXN - Peso Mexicano
    //USD - Dolar Estadounidense
    //CAD - Dolar Canadiense
    //EUR - Euro
    //GBP - Libra Esterlina
    //JPY - Yen
    //CNY - Yuan
int main(){
    float MXN;
    int DIVISA;
    printf("CONVERSOR DE DIVISAS\n\n");
    printf("Introduzca la cantidad en pesos mexicanos: $");
    scanf("%f",&MXN);
    printf("\nDivisas Disponibles:\n\n");
    printf("1. Dolar Estadounidense (USD)\n");
    printf("2. Dolar Canadiense (CAD)\n");
    printf("3. Euro (EUR)\n");
    printf("4. Libra esterlina (GBP)\n");
    printf("5. Yen (JPY)\n");
    printf("6. Yuan (CNY)\n\n");
    printf("Elija el numero de la divisa a la que desea convertir: ");
    scanf("%i",&DIVISA);
    printf("\n");
    if(DIVISA<=0||DIVISA>6)
        printf("Divisa Invalida\n");
    if(DIVISA==1)
        printf("El valor en Dolares Estadounidenses (USD) es: $%f\n",MXN/USD);
    if(DIVISA==2)
        printf("El valor en Dolares Canadienses (CAD) es: $%f\n",MXN/CAD);
    if(DIVISA==3)
        printf("El valor en Euros (EUR) es: %f\n",MXN/EUR);
    if(DIVISA==4)
        printf("El valor en Libras Esterlinas (GBP) es: %f\n",MXN/GBP);
    if(DIVISA==5)
        printf("El valor en Yenes (JPY) es: %f\n",MXN/JPY);
    if(DIVISA==6)
        printf("El valor en Yuanes (CNY) es: %f\n",MXN/CNY);
    return 0;

}

