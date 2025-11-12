#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define M 20.19
#define P 21.65
#define D 22.06
#define GALON 3.785
int main(){
    float LITROS,i,x,PRECIO,LITROS_TOTALES=0,DINERO_TOTAL=0,TOTAL_M=0,TOTAL_P=0,TOTAL_D=0;
    char TIPO;
    do{
    printf("GASOLINERA\n\n");
    printf("Seleccione el tipo de gasolina\n\nA. Magna\nB. Premium\nC. Diesel\nD. Salir\n\nTipo: ");
    fflush(stdin);
    scanf("%c",&TIPO);
    while(TIPO!='A'&&TIPO!='a'&&TIPO!='B'&&TIPO!='b'&&TIPO!='C'&&TIPO!='c'&&TIPO!='D'&&TIPO!='d')
    {
        printf("Seleccione una opcion valida: ");
        fflush(stdin);
        scanf("%c",&TIPO);
    }
    if(TIPO!='D'&&TIPO!='d')
    {
        printf("\nIntroduzca los litros de gasolina: ");
        scanf("%f",&LITROS);
        LITROS_TOTALES+=LITROS;
        switch(TIPO)
        {
        case 'A':
            PRECIO=M;
        break;
        case 'a':
            PRECIO=M;
        break;
        case 'B':
            PRECIO=P;
        break;
        case 'b':
            PRECIO=P;
        break;
        case 'C':
            PRECIO=D;
        break;
        case 'c':
            PRECIO=D;
        break;
        }
        for(i=0;i<=LITROS;i+=0.01)
        {
            system("cls");
            printf("LITROS: %.2fL\nPRECIO: $%.2f",i,i*PRECIO);
            Sleep(10);
        }
        printf("\n\n");
        system("PAUSE");
        system("cls");
        DINERO_TOTAL+=LITROS*PRECIO;
        switch(TIPO)
        {
        case 'A':
            TOTAL_M+=LITROS;
        break;
        case 'a':
            TOTAL_M+=LITROS;
        break;
        case 'B':
            TOTAL_P+=LITROS;
        break;
        case 'b':
            TOTAL_P+=LITROS;
        break;
        case 'C':
            TOTAL_D+=LITROS;
        break;
        case 'c':
            TOTAL_D+=LITROS;
        break;
        }
    }
    }while(TIPO!='D'&&TIPO!='d');
    system("cls");
    printf("GASOLINERA\n\nTotal de Dinero recaudado: $%.2f\nTotal de Galones vendidos: %.2f\nGalones de Gasolina Magna vendidos: %.2f\nGalones de Gasolina Premium vendidos: %.2f\nGalones de Diesel vendidos: %.2f\n",DINERO_TOTAL,LITROS_TOTALES/3.785,TOTAL_M,TOTAL_P,TOTAL_D);
    return 0;
}
