/*
Juan Antonio Arroyo Santana - INNI
Práctica 7
Realice un programa que pida al usuario su fecha de nacimiento e indique cuántos meses han pasado desde entonces.
*/
#include <stdio.h>
#define D 2
#define M 10
#define Y 2020
int main(){
    int DAY,MONTH,YEAR,X;
    printf("Dia de Nacimiento: ");
    scanf("%i",&DAY);
    printf("Mes de Nacimiento: ");
    scanf("%i",&MONTH);
    printf("Año de Nacimiento: ");
    scanf("%i",&YEAR);
    if(DAY>D&&MONTH>M&&YEAR>=Y||DAY>D&&MONTH>=M&&YEAR>=Y||DAY>=D&&MONTH>M&&YEAR>=Y||MONTH>M&&YEAR>=Y||YEAR>Y||DAY>31||MONTH==2&&DAY>29||MONTH==4&&DAY>30||MONTH==6&&DAY>30||MONTH==9&&DAY>30||MONTH==11&&DAY>30||DAY<1||MONTH<1)
        printf("Fecha invalida");
    if(YEAR<=Y)
        if(MONTH>1&&DAY>1||MONTH<12&&DAY>1)
            if(MONTH==1&&DAY<32||MONTH==2&&DAY<30||MONTH==3&&DAY<32||MONTH==4&&DAY<31||MONTH==5&&DAY<32||MONTH==6&&DAY<31||MONTH==7&&DAY<32||MONTH==8&&DAY<32||MONTH==9&&DAY<31||MONTH==10&&DAY<32||MONTH==11&&DAY<31||MONTH==12&&DAY<32)
            {
                X=(Y-YEAR)*12;
                if(MONTH==M)
                {
                    if(D<DAY)
                    X-1;
                    printf("\nEl numero de meses es: %i",X);
                }
                if(MONTH>M)
                {
                    X=X-(MONTH-M);
                    if(D<DAY)
                        X=X-1;
                    printf("\nEl numero de meses es: %i",X);
                }
                if(M>MONTH)
                {
                    X=X+(M-MONTH);
                    if(D<DAY)
                        X=X-1;
                    printf("\nEl numero de meses es: %i",X);
                }
            }
            return 0;

}
