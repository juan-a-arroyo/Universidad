#include <stdio.h>
int main()
{
    float W,X,Y,Z;
    printf("CALCULAR MEDIA DE 4 NUMEROS\nIntroduzca 4 Numeros: \n");
    scanf("%f %f %f %f",&W,&X,&Y,&Z);
    printf("La media es: %.2f\n",(W+X+Y+Z)/4);
    return 0;
}
