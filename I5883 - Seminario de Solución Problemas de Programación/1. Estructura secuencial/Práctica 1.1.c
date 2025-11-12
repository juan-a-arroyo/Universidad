//Juan Antonio Arroyo Santana - INNI
//Práctica 2
//Realice un programa que pida un numero entero, un numero flotante, un carácter, un double y un entero sin signo, a cada variable súmele un numero pedido al usuario y muestre en pantalla.
#include <stdio.h>
int main ()
{
    int ENTERO, X;
    float FLOTANTE;
    char CARACTER;
    double DOBLE;
    unsigned int ENTERO_SIN_SIGNO;

    printf("Inserte el numero que va a sumar: ");
    scanf("%i",&X);

    printf("Inserte un numero entero: ");
    scanf("%i",&ENTERO);
    ENTERO+=X;
    printf("El resultado es: %i\n",ENTERO);

    printf("Inserte un numero flotante: ");
    scanf("%f",&FLOTANTE);
    FLOTANTE+=X;
    printf("El resultado es: %f\n",FLOTANTE);

    printf("Inserte un caracter: ");
    fflush(stdin);
    scanf("%c",&CARACTER);
    CARACTER+=X;
    printf("El resultado es: %c\n",CARACTER);

    printf("Inserte un numero doble: ");
    fflush(stdin);
    scanf("%lf",&DOBLE);
    DOBLE+=X;
    printf("El resultado es: %lf\n",DOBLE);

    printf("Inserte un numero entero sin signo: ");
    fflush(stdin);
    scanf("%u",&ENTERO_SIN_SIGNO);
    ENTERO_SIN_SIGNO+=X;
    printf("El resultado es: %u\n",ENTERO_SIN_SIGNO);

    return 0;


}
