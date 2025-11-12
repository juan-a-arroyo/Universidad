/*
Juan Antonio Arroyo Santana - INNI (220792779)
1.- Realice un programa que convierta un numero base diez pedido al usuario en su correspondiente base 2, base 8 y base 16.
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int OPCION=0,NUMERO,DIVIDENDO,RESIDUO,i;
    printf("CONVERSOR DE BINARIO A BASE\n\n");
    printf("%cA qu%c base desea convertir?\n",168,130);
    printf("\n1.Base 2 (Binario)\n2.Base 8 (Octal)\n3.Base 16 (Hexadecimal)\n4.Salir\n\nSeleccione una opci%cn: ",162);
    scanf("%d",&OPCION);
    while(OPCION<1||OPCION>4)
    {
        printf("Seleccione una opci%cn v%clida: ",162,160);
        scanf("%d",&OPCION);
    }
    switch (OPCION)
    {
    case 1:
        DIVIDENDO=2;
    break;
    case 2:
        DIVIDENDO=8;
    break;
    case 3:
        DIVIDENDO=16;
    break;
    case 4:
        printf("Gracias por usar");
    break;
    }
    if(OPCION>0&&OPCION<4)
    {
        printf("\n%cQu%c n%cmero desea convertir?: ",168,130,163);
        scanf("%d",&NUMERO);
        printf("\t\t");
        for(NUMERO;NUMERO>=DIVIDENDO;NUMERO=NUMERO/DIVIDENDO)
        {
            RESIDUO=NUMERO%DIVIDENDO;
            switch (RESIDUO)
            {
            case 10:
                printf("A");
            break;
            case 11:
                printf("B");
            break;
            case 12:
                printf("C");
            break;
            case 13:
                printf("D");
            break;
            case 14:
                printf("E");
            break;
            case 15:
                printf("F");
            break;
            default:
               printf("\b\b%d",RESIDUO);
            }
        }
        printf("\b\b%d",NUMERO);
    }
    printf("\n");
    return 0;
}
