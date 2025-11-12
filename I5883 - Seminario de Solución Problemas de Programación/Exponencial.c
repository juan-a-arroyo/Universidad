#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (){
    double x,e,i,f;
    char opc;
    printf("Deseas hacer un calculo de Exponencial? si(S) no(N): ");
    fflush(stdin);
    scanf("%c",&opc);
    while(opc!='s'&&opc!='S'&&opc!='n'&&opc!='N')
    {
        printf("Seleccione una opcion valida: ");
        fflush(stdin);
        scanf("%c",&opc);
    }
    while(opc=='s'||opc=='S')
    {
        system("cls");
        printf("Ingresa un numero: ");
        scanf("%lf",&x);
        e=1;
        f=1;
        i=1;
        while(i<=100)
        {
            f=f*i;
            e=e+pow(x,i)/f;
            i++;
        }
        printf("%lf",e);
        printf("\nDeseas hacer otro calculo? si(S) no(N): ");
        fflush(stdin);
        scanf("%c",&opc);
        while(opc!='s'&&opc!='S'&&opc!='n'&&opc!='N')
        {
            printf("Seleccione una opcion valida: ");
            fflush(stdin);
            scanf("%c",&opc);
        }
    }
    return 0;
}
