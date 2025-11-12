#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,A1,B1,A2,B2,A3,B3;
    printf("Inserte medidas de los dos catetos: \n");
    scanf("%f %f",&a,&b);
    A1=pow(a,2);
    B1=pow(b,2);
    c=sqrt(A1+B1);
    A2=asin(a/c);
    B2=asin(b/c);
    A3=A2*57.29578;
    B3=B2*57.29578;
    printf("La medida de la Hipotenusa es: %.2f unidades\n",c);
    printf("La medida del angulo Alpha es: %.2f grados\nLa medida del angulo Beta es: %.2f grados",A3,B3);
    return 0;
}
