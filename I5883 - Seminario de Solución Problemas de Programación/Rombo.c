#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int ANCHO,ALTO,ESPACIOS,i,j,k,A;
    printf("ROMBO\n\nIntroduzca el valor al cuadrado del ancho del Rombo: ");
    scanf("%d",&ANCHO);
    /*for(i=0;i<=ANCHO;i++)
    {
        ESPACIOS=(pow(2,ANCHO))-(pow(2,i));
        for(j=1;j<=ESPACIOS;j++)
            printf(" ");
        A=pow(2,i);
        for(j=1;j<=A;j++)
            printf("* ");
        printf("\n\n");
    }
    for(i=ANCHO-1;i>=0;i--)
    {
        ESPACIOS=(pow(2,ANCHO))-(pow(2,i));
        for(j=1;j<=ESPACIOS;j++)
            printf(" ");

        A=pow(2,i);
        for(j=1;j<=A;j++)
            printf("* ");
        printf("\n\n");
    }*/
    ALTO=pow(2,ANCHO);
    printf("%d",ALTO);
    for(i=0;i<=ALTO;i++)
    {
        //for(j=0;j<=ANCHO;j++)
        //{
            //ESPACIOS=pow(2)
            for(k=0;k<=ANCHO;k++)
            {
                printf("++");
            }
            printf("\n");
        //}
    }
    return 0;
}
