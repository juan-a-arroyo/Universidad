/*
Juan Antonio Arroyo Santana - INNI (220792779)
6.- Realice un algoritmo que pida al usuario un rango especificado por 2 números enteros,
tal que el primero sea menor al segundo. El algoritmo deberá contar el número de múltiplos
de 3 que existe en el rango. Ejemplo, si se introduce 2 y 21, el número de múltiplos de 3 es 7,
dado que 3,6,9,12,15,18 y 21 son múltiplos de 3 en el rango de 2 a 21.
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int INICIO,FIN,i,MULTIPLOS=0;
    printf("MULTIPLOS DE 3\n\n");
    printf("Ingrese el n%cmero de inicio: ",163);
    scanf("%d",&INICIO);
    printf("Ingrese el n%cmero de fin: ",163);
    scanf("%d",&FIN);
    while(INICIO>FIN)
    {
        printf("El n%cmero no es v%clido, ingrese un n%cmero v%clido: ",163,160,163,160);
        scanf("%d",&FIN);
    }
    for(i=INICIO;i<=FIN;i++)
    {
        if(i%3==0&&i!=0)
        {
            printf("%d, ",i);
            MULTIPLOS++;
        }

    }
    printf("\n\nEl n%cmero de m%cltiplos en ese rango es: %d\n",163,163,MULTIPLOS);
    return 0;
}
