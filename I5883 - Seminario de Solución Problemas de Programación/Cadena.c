#include <stdio.h>
#include <stdlib.h>
char minusculas();
char mayusculas();

int main ()
{
    int i, opc;
    char cadena[100]={};
    printf("Introduzca una cadena: ");
    gets(cadena);
    printf("Convertir a:\n\n1.Minusculas\n2.Mayusculas\n\nSeleccione una opcion: ");
    do{
    scanf("%d",&opc);
    }while(opc!=1&&opc!=2);
    for(i=0;i<100;i++)
    {
        if(opc==1)
        {
            minusculas(cadena, i);
            printf("%c",minusculas(cadena, i));
            if(minusculas(cadena, i)=='\0')
            break;
        }
        else
        {
            mayusculas(cadena, i);
            printf("%c",mayusculas(cadena, i));
            if(mayusculas(cadena, i)=='\0')
            break;
        }

    }

    /*for(i=0;i<100;i++)
    {
        /*if(cadena[i]>=65&&cadena[i]<=90)
            printf("%c",cadena[i]+32);
        else
            printf("%c",cadena[i]);
        if(cadena[i]>=97&&cadena[i]<=122)
            printf("%c",cadena[i]-32);
        else
            printf("%c",cadena[i]);
    }*/
    //printf("%s",cadena);
    return 0;
}
char minusculas(char cad[100], int x)
{
    char minus;
    //for(i=0;i<100;i++)
    //{
        if(cad[x]>=65&&cad[x]<=90)
            minus=cad[x]+32;
            //printf("%c",cad[i]+32);
        else
            minus=cad[x];
            //printf("%c",cad[i]);
    //}
    //printf("%s",cad);
    return minus;
}

char mayusculas(char cad[100], int x)
{
    char mayus;
    //for(i=0;i<100;i++)
    //{
        if(cad[x]>=97&&cad[x]<=122)
            mayus=cad[x]-32;
            //printf("%c",cad[i]+32);
        else
            mayus=cad[x];
            //printf("%c",cad[i]);
    //}
    //printf("%s",cad);
    return mayus;
}
