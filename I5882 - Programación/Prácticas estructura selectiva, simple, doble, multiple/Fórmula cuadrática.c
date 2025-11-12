#include <stdio.h>
#include <math.h>
int main (){
    float a,b,c,X1,X2,P,R,D;
    printf("CALCULADORA DE ECUACIONES CUADRATICAS\nInserte valores a, b y c: \n");
    scanf("%f %f %f",&a,&b,&c);
    if (a!=0)
    {
        printf("Es una ecuacion cuadratica\nSu ecuacion es %.0fx^2 + %.0fx + %.0f",a,b,c);
        P=pow(b,2);
        D=(P-(4*a*c));
        R=sqrt(D);
        if(D>=0)
        {
            if(D>0)
            {
                X1=((-(b))+(R))/(2*a);
                X2=((-(b))-(R))/(2*a);
                printf("\nLas Soluciones son reales y distintas dadas por: x1,x2=(-b+- rc(discriminante))/2a \nLa solucion 1 es: %.1f\nLa solucion 2 es: %.1f",X1,X2);
            }
            else
            {
                X1=(-b)/(2*a);
                printf("\nLas soluciones son iguales dadas por: x1=x2=-b/2a \nLa solucion es: %.1f",X1);
            }

        }
        else
        {
            printf("\nLas soluciones son complejas conjugadas por la formula: x1,x2=(-b+-i rc(discriminante))/2a\n-%.1f+-rc(%.1f)i/%.1f",b,D,2*a);
        }
    }
    else
        printf("No es una ecuacion cuadratica");

    return 0;
}
