/*
Juan Antonio Arroyo Santana - INNI (220792779)
3.- Realice un programa que muestre la figura siguiente:

* * * * * * * * * *
*                 *
*                 *
*                 *
*                 *
*                 *
*                 *
*                 *
*                 *
* * * * * * * * * *

deberá usar ciclo(s) for y las instrucciones que se repiten son:
printf(“*”);		o 		printf(“ “);
*/
#include <stdio.h>
#include <stdlib.h>
int main () {
    int A,B;
    printf("CUADRADO\n\n");
    for(A=1;A<=10;A++)
    {
        for(B=1;B<=10;B++)
        {
            if(A==1||A==10)
            printf("*");
            else
            if(B==1||B==10)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
