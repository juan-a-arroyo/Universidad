#include <stdio.h>
#include <math.h>
int main (){
    int a,b,c,X1,X2,P,R;
    printf("CALCULADORA DE ECUACIONES CUADRATICAS\nInserte valores a, b y c: \n");
    scanf("%d %d %d",&a,&b,&c);
    P=pow(b,2);
    R=sqrt(P-(4*a*c));
    if((P-(4*a*c))>=0)
    {
        X1=(-(b)+(R))/2*a;
        X2=(-(b)-(R))/2*a;
        printf("La solucion 1 es: %d\n",X1);
        printf("La solucion 2 es: %d",X2);
    }
    else
        printf("No tiene solucion");
    return 0;
}
