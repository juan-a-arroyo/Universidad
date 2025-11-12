/*
Juan Antonio Arroyo Santana - INNI
Práctica 5
Realice un programa que pida tres números y muestre en pantalla cuál es el mayor y el menor,
considere el caso en el que los 3 números son iguales o al menos dos de ellos son iguales.
*/
#include <stdio.h>
int main(){
    int A,B,C;
    printf("Inserte tres numeros: \n");
    scanf("%i",&A);
    scanf("%i",&B);
    scanf("%i",&C);
    if(A>B&&A>C||A==B&&A>C||A==C&&A>B)
        printf("El numero mayor es %i",A);
    if(B>A&&B>C)
        printf("El numero mayor es %i",B);
    if(C>A&&C>B)
        printf("El numero mayor es %i",C);
    if(A<B&&A<C||A==B&&A<C||A==C&&A<B)
        printf("\nEl numero menor es %i",A);
    if(B<A&&B<C)
        printf("\nEl numero menor es %i",B);
    if(C<A&&C<B)
        printf("\nEl numero menor es %i",C);
    if(A==B&&A==C)
        printf("Todos los numeros son iguales a: %i",A);
    return 0;

}
