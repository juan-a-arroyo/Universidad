/*
Juan Antonio Arroyo Santana - INNI (220792779)
2.- Realice un programa que mediante el uso del ciclo desde muestre en pantalla X números de la serie fibonacci.
la serie fibonacci es una sucesión de números que comienza con los valores 0,1 en la que el resultado del próximo número
corresponde a la suma de los dos anteriores, ejemplo:
mostrar 5 números de la serie fibonacci
0, 1, 1, 2, 3, 5, 8
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    double A=1,B=0,C,N,i;
    printf("SUCESI%cN DE FIBONACCI\n\n%cHasta qu%c n%cmero desea mostrar?: ",224,168,130,163);
    scanf("%lf",&N);
    for(i=1;i<=N+C;i=i+C){
        C=A+B;
        printf("%.0lf, ",C);
        A=B;
        B=C;
    }
    return 0;
}
