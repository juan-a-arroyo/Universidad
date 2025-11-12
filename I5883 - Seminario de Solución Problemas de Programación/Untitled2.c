#include <stdio.h>
#include <stdlib.h>
int main (){
    int DEPOSITO=0,RETIRO=0,SALDO=0;
    char TRANSACCION;
    do{
        TRANSACCION=0;
        RETIRO=0;
        DEPOSITO=0;
        printf("CUENTA BANCARIA\n\n");
        printf("%cQu%c tipo de transacci%cn va a realizar\nDep%csito (D) Retiro (R) Salir (ENTER)\n",168,130,162,162);
        do{
            if(TRANSACCION!=0&&TRANSACCION!='D'&&TRANSACCION!='d'&&TRANSACCION!='R'&&TRANSACCION!='r')
                printf("\nSeleccione una opci%cn v%clida",162,160);
            fflush(stdin);
            scanf("%c",&TRANSACCION);
        }while(TRANSACCION!='\n'&&TRANSACCION!='D'&&TRANSACCION!='d'&&TRANSACCION!='R'&&TRANSACCION!='r');
        switch(TRANSACCION){
        case 'D':
            printf("Ingrese el monto a depositar: $");
            scanf("%d",&DEPOSITO);
            SALDO=SALDO+DEPOSITO;
        break;
        case 'd':
            printf("Ingrese el monto a depositar: $");
            scanf("%d",&DEPOSITO);
            SALDO=SALDO+DEPOSITO;
        break;
        case 'R':
            printf("Ingrese el monto a retirar: $");
            scanf("%d",&RETIRO);
            if(RETIRO<SALDO)
                SALDO=SALDO-RETIRO;
            else
                printf("\nSaldo Insuficiente\n");
        break;
        case 'r':
            printf("Ingrese el monto a retirar: $");
            scanf("%d",&RETIRO);
            if(RETIRO<SALDO)
                SALDO=SALDO-RETIRO;
            else
                printf("\nSaldo Insuficiente\n");
        break;
        }
        system("PAUSE");
        system("cls");
    }while(TRANSACCION!='\n');
    printf("Tu saldo final es: $%d\n",SALDO);
    return 0;
}
