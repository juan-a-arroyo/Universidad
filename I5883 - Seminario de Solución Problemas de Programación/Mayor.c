/*
Juan Antonio Arroyo Santana - INNI (220792779)
3.- Realice un algoritmo que diga cual es el número mayor de un conjunto de 10 números pedidos al usuario
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int NUMERO,MAYOR=(-2147483648),CUENTA=1;
    printf("PROGRAMA QUE INDICA CU%cL ES MAYOR DE 10 N%cMEROS\n\n",181,233);
    printf("Ingrese 10 N%cmeros:\n",233);
    do{
        scanf("%d",&NUMERO);
        if (NUMERO>MAYOR)
            MAYOR=NUMERO;
        CUENTA++;
    }while(CUENTA<=10);
    printf("El n%cmero mayor es: %d\n",163,MAYOR);
    return 0;
}
