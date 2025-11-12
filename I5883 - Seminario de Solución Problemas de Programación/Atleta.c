#include <stdio.h>
#include <stdlib.h>

struct datos
{
    char nombre[40];
    char pais[25];
};

struct atleta
{
    char deporte[30];
    struct datos pers;
    int nmedallas;
};

struct atleta ats[10];

int main()
{
    int i, may=0, x;
    printf("Atleta\n\n");
    for(i=0;i<10;i++)
    {
        printf("Ingrese Deporte del atleta %d: \n",i+1);
        fflush(stdin);
        gets(ats[i].deporte);
        printf("Ingrese Nombre del atleta %d: \n",i+1);
        fflush(stdin);
        gets(ats[i].pers.nombre);
        printf("Ingrese Pais del atleta %d: \n",i+1);
        fflush(stdin);
        gets(ats[i].pers.pais);
        printf("Ingrese el numero de medallas del atleta %d: \n",i+1);
        scanf("%d",&ats[i].nmedallas);
    }
    for(i=0;i<10;i++)
    {
        if(ats[i].nmedallas)
            may=ats[i].nmedallas;
    }
    for(i=0;i<10;i++)
    {
        if(ats[i].nmedallas==may)
            x=i;
    }
    //printf("Ingrese Deporte, nombre pais y numero de medallas del atleta %d: \n",i+1);
        system("cls");
        printf("\nDeporte del atleta: ");
        printf("%s",ats[x].deporte);
        printf("\nNombre del atleta: ");
        printf("%s",ats[x].pers.nombre);
        printf("\nPais del atleta: ");
        printf("%s",ats[x].pers.pais);
        printf("\nNumero de medallas del atleta: ");
        printf("%d",ats[x].nmedallas);
        return 0;
}
