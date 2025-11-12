#include <stdio.h>
#include <stdlib.h>
int main(){
    float X,Y,i;
    printf("BANCO\n\n");
    printf("Ingrese el monto total del prestamo: $");
    scanf("%f",&X);
    printf("Ingrese el monto de los pagos mensuales: $");
    scanf("%f",&Y);
    printf("Seleccione el porcentaje de interes: ");
    scanf("%f",&i);
    system("cls");
    printf("La cantidad de intereses que se pagaran cada mes es de: $%.2f\n",Y*i*.01);
    printf("La cantidad de dinero aplicada cada mes es de: $%.2f",Y-(Y*i*.01));
}
