#include <stdio.h>
#include <stdlib.h>
int main (){
    int NUMERO;
    printf("Introduzca un numero de 4 cifras: ");
    scanf("%d",&NUMERO);
    while(NUMERO<1000||NUMERO>9999)
    {
        printf("Numero invalido, introduzca un numero valido: ");
        scanf("%d",NUMERO);
    }
    if(NUMERO%2==0)
    {
        while(NUMERO%10!=0)
            NUMERO--;
        if(NUMERO%20==0)
        {
            while(NUMERO%100!=0)
                NUMERO-=10;
            if(NUMERO%200==0)
            {
                while(NUMERO%1000!=0)
                    NUMERO-=100;
                if(NUMERO%2000==0)
                {
                    printf("Todas sus cifras son pares");
                }
                else
                    printf("Tiene cifras impares");
            }
            else
                printf("Tiene cifras impares");
        }
        else
            printf("Tiene cifras impares");
    }
    else
        printf("Tiene cifras impares");
    return 0;
}
