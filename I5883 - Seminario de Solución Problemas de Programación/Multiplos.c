/*
Juan Antonio Arroyo Santana - INNI (220792779)
1.- Realice un algoritmo que muestre un menú con las opciones
        1.Múltiplos de 2
        2.Múltiplos de 3
        3.Múltiplos de 5
        4.Multiplos de 7
        5.Múltiplos de 11
        6.Salir
Nota: el algoritmo exclusivamente mostrará los 100 primeros múltiplos del número seleccionado.
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int OPCION,MULTIPLO,X,CUENTA=1;
    printf("M%cLTIPLOS\n\n",233);
    printf("1.M%cltiplos de 2\n2.M%cltiplos de 3\n3.M%cltiplos de 5\n4.M%cltiplos de 7\n5.M%cltiplos de 11\n6.Salir",163,163,163,163,163);
    printf("\n\nIngrese la opci%cn de los m%cltiplos que desea: ",162,163);
    do{
    scanf("%d",&OPCION);
    if(OPCION<1||OPCION>6)
        printf("\nIngrese una opci%cn correcta: ",162);
    }while(OPCION<1||OPCION>6);
    switch(OPCION){
    case 1:
        MULTIPLO=2;
    break;
    case 2:
        MULTIPLO=3;
    break;
    case 3:
        MULTIPLO=5;
    break;
    case 4:
        MULTIPLO=7;
    break;
    case 5:
        MULTIPLO=11;
    break;
    }
    do{
        X=MULTIPLO*CUENTA;
        printf("%d, ",X);
        CUENTA++;
    }while(CUENTA<=100);
    printf("\n");
    return 0;
}
