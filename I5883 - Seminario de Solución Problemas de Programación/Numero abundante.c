/*
Juan Antonio Arroyo Santana - INNI (220792779)
7.- Realice un programa que permita calcular si un número es abundante. En matemáticas,
un número abundante o número excesivo es un número para el cual la suma de todos los divisores es mayor
que el doble del numero. num > 2num su abundancia se calcula con sumaDivisores − 2num = abundancia.
un número abundante N es aquel en el que la suma de sus divisores incluido el mismo es mayor al N+N
Ejemplo, se tiene el número 24.
los divisores para este número son: 1, 2, 3, 4, 6, 8, 12, 24  cuya suma es 60.
Puesto que 60 es mayor que 2 x 24=48, el número 24 es abundante. Y su abundancia es  60 −( 2 x 24) = 12.  ( (36 + 24) − 2 x 24)
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int SUMA=0,NUMERO,i;
    printf("N%cMERO ABSOLUTO\n\n",233);
    printf("Ingrese el n%cmero a evaluar: ",163);
    scanf("%d",&NUMERO);
    for(i=1;i<=NUMERO;i++)
    {
        if(NUMERO%i==0)
            SUMA=SUMA+(NUMERO/i);
    }
    if(SUMA>NUMERO*2)
    {
        printf("\n%d es un n%cmero abundante\n",NUMERO,163);
        printf("Su abundancia es: %d-(2%c%d) = %d. ((%d+%d)-2%c%d)",SUMA,158,NUMERO,SUMA-(2*NUMERO),SUMA-NUMERO,NUMERO,158,NUMERO);
        //60 −( 2 x 24) = 12.  ( (36 + 24) − 2 x 24)
    }
    else
        printf("\n%d no es un n%cmero abundante\n",NUMERO,163);
    printf("\nLa suma de sus divisores es: %d\n",SUMA);
    return 0;
}
