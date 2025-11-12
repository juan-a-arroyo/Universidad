#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159
int main(void)
{
    int radio, diametro;
    float circunferencia, area;
    printf("Ingrese el radio del circulo: ");
    scanf("%d",&radio);
    diametro=radio*2;
    circunferencia=diametro*pi;
    area=pi*(pow(radio,2));
    printf("El diametro es: %d\nLa circunferencia es: %f\nEl area es: %f\n",diametro,circunferencia,area);
    system("PAUSE");
    return 0;
}