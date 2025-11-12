#include <stdio.h>

int main()
{
    float R1,R2,RT;
    printf("PROGRAMA QUE CALCULA LA RESISTENCIA EQUIVALENTE DE 2 RESISTENCIAS EN PARALELO\n");
    printf("Valor de la resistencia 1: ");
    scanf("%f",&R1);
    printf("Valor de la resistencia 2: ");
    scanf("%f",&R2);
    RT=(R1*R2)/(R1+R2);
    printf("El valor de la resistencia equivalente es de: %.2fohm\n",RT);
    return 0;
}
