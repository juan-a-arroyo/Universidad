/*
Juan Antonio Arroyo Santana - INNI
Práctica 4
Realice un programa que pida una fecha (dia y mes) y muestre la fecha anterior, considere el caso del mes 2.
*/
#include <stdio.h>
int main(){
    int DIA,MES,DIA_X;
    printf("FECHA ANTERIOR\n\n");
    printf("Introduzca dia: ");
    scanf("%i",&DIA);
    printf("Introduzca mes: ");
    scanf("%i",&MES);
    if(MES<1||MES>12||DIA<1||DIA>31||MES==2&&DIA>28||MES==4&&DIA>30||MES==6&&DIA>30||MES==9&&DIA>30||MES==11&&DIA>30)
        printf("Dia o Mes Invalido");

        if(MES==1&&DIA>1&&DIA<32)
            printf("El dia anterior es: %i de Enero",DIA-1);
        if(MES==2&&DIA==1)
            printf("El dia anterior es: %i de Enero",DIA+30);

        if(MES==2&&DIA>1&&DIA<30)
            printf("El dia anterior es: %i de Febrero",DIA-1);
        if(MES==3&&DIA==1){
            printf("El dia anterior es: %i de Febrero",DIA+27);
            printf("\nSi es año bisiesto el dia anterior es: %i de Febrero",DIA+28);
        }
        if(MES==3&&DIA>1&&DIA<32)
            printf("El dia anterior es: %i de Marzo",DIA-1);
        if(MES==4&&DIA==1)
            printf("El dia anterior es: %i de Marzo",DIA+30);

        if(MES==4&&DIA>1&&DIA<31)
            printf("El dia anterior es: %i de Abril",DIA-1);
        if(MES==5&&DIA==1)
            printf("El dia anterior es: %i de Abril",DIA+29);

        if(MES==5&&DIA>1&&DIA<32)
            printf("El dia anterior es: %i de Mayo",DIA)-1;
        if(MES==6&&DIA==1)
            printf("El dia anterior es: %i de Mayo",DIA+30);

        if(MES==6&&DIA>1&&DIA<31)
            printf("El dia anterior es: %i de Junio",DIA-1);
        if(MES==7&&DIA==1)
            printf("El dia anterior es: %i de Junio",DIA+29);

        if(MES==7&&DIA>1&&DIA<32)
            printf("El dia anterior es: %i de Julio",DIA-1);
        if(MES==8&&DIA==1)
            printf("El dia anterior es: %i de Julio",DIA+30);

        if(MES==8&&DIA>1&&DIA<32)
            printf("El dia anterior es: %i de Agosto",DIA-1);
        if(MES==9&&DIA==1)
            printf("El dia anterior es: %i de Agosto",DIA+30);

        if(MES==9&&DIA>1&&DIA<31)
            printf("El dia anterior es: %i de Septiembre",DIA-1);
        if(MES==10&&DIA==1)
            printf("El dia anterior es: %i de Septiembre",DIA+29);

        if(MES==10&&DIA>1&&DIA<32)
            printf("El dia anterior es: %i de Octubre",DIA-1);
        if(MES==11&&DIA==1)
            printf("El dia anterior es: %i de Octubre",DIA+30);

        if(MES==11&&DIA>1&&DIA<31)
            printf("El dia anterior es: %i de Noviembre",DIA-1);
        if(MES==12&&DIA==1)
            printf("El dia anterior es: %i de Noviembre",DIA+29);

        if(MES==12&&DIA>1&&DIA<32)
            printf("El dia anterior es: %i de Diciembre",DIA-1);
        if(MES==1&&DIA==1)
            printf("El dia anterior es: %i de Diciembre",DIA+30);
    return 0;
}
