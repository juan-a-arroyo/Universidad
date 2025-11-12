/*
Juan Antonio Arroyo Santana - INNI
Práctica 1
Realice un programa que pida un número correspondiente al mes del año,
deberá evaluar que el número esté entre 1 y 12 y mostrará en la pantalla el mes al que pertenece.
*/
#include <stdio.h>
int main (){
    int MES;
    printf("Inserte el numero de mes: ");
    scanf("%i",&MES);
    if(MES==1)
        printf("Enero\n");
    if(MES==2)
        printf("Febero\n");
    if(MES==3)
        printf("Marzo\n");
    if(MES==4)
        printf("Abril\n");
    if(MES==5)
        printf("Mayo\n");
    if(MES==6)
        printf("Junio\n");
    if(MES==7)
        printf("Julio\n");
    if(MES==8)
        printf("Agosto\n");
    if(MES==9)
        printf("Septiembre\n");
    if(MES==10)
        printf("Octubre\n");
    if(MES==11)
        printf("Noviembre\n");
    if(MES==12)
        printf("Diciembre\n");
    if(MES<=0||MES>12)
        printf("Mes Invalido\n");
    return 0;
}
