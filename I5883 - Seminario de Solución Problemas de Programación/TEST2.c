#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
    int a, b, c, suma, producto;
    float promedio;
    printf("Introduzca tres enteros distintos: ");
    scanf("%d %d %d",&a,&b,&c);
    suma=a+b+c;
    promedio=(a+b+c)/3;
    producto=a*b*c;
    printf("La Suma es: %d\nEl promedio es: %.2f \nEl producto es: %d\n\n",suma,promedio,producto);
    system("PAUSE");
    return 0;
}