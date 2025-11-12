/*AGENCIA DE VENTA DE VEHICULOS*/

/*SEMINARIO DE PROGRAMACION
Juan Antonio Arroyo Santana
Sergio Adrian Guillen Lopez
Brandon Ariel Ornelas Valadez*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VENDEDORES 10
#define MODELOS 15
#define NOMBRE 30
#define CANTIDAD 999

int i, j, k, FULL_TOTAL=0, totals[MODELOS]={},copyVend[VENDEDORES],copyMod[MODELOS];
char input[NOMBRE];

struct venta
{
    char nombre[NOMBRE];
    int modelo[MODELOS];
    int total;
}vendedor[VENDEDORES];

struct venta vendedor[VENDEDORES]={};

void capturarNombres();
void mostrarNombres();
void leerVendedor();
void capturarVenta();
void eliminarVenta();
int compararVendedor();
void mostrarTabla();
void mostrarMatriz();
int len();
void totales();
void ranking();

int main()
{
    int x, opcion;
    printf("AGENCIA DE VENTA DE VEHICULOS.\n\n");
    printf("Debera Ingresar el nombre de los 10 vendedores.\n");
    capturarNombres();
    do{
        system("cls");
        printf("AGENCIA DE VENTA DE VEHICULOS.\n\n");
        printf("MENU DE OPCIONES.\n\n");
        printf("Escoje la accion a realizar.\n");
        printf("\n0. Mostrar Vendedores."
               "\n1. Capturar ventas de un vendedor."
               "\n2. Mostrar Ranking de los vendedores."
               "\n3. Eliminar ventas de un vendedor."
               "\n4. Buscar vendedor."
               "\n5. Mostrar lista de modelos de auto mas vendidos."
               "\n6. Informe mensual."
               "\n7. Salir del programa."
               "\n\nEleccion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 0:
            system("cls");
            printf("Vendedores.\n\n");
            mostrarNombres();
            system("PAUSE");
        break;
        case 1:
            system("cls");
            printf("Capturar una venta.\n\n");
            leerVendedor();
            capturarVenta(compararVendedor(input));
        break;
        case 2:
            system("cls");
            printf("Ranking de vendedores.\n\n");
            ranking(VENDEDORES);
        break;
        case 3:
            system("cls");
            printf("Eliminar una venta.\n\n");
            leerVendedor();
            eliminarVenta(compararVendedor(input));
        break;
        case 4:
            system("cls");
            printf("Buscar vendedor.\n\n");
            leerVendedor();
            mostrarTabla();
            mostrarMatriz(compararVendedor(input));
            system("PAUSE");
        break;
        case 5:
            system("cls");
            printf("Lista de modelos de auto mas vendidos.\n\n");
            ranking(MODELOS);
        break;
        case 6:
            system("cls");
            printf("Informe mensual.\n\n");
            mostrarTabla();
            for(k=0;k<VENDEDORES;k++)
                mostrarMatriz(k);
            totales();
            printf("\n");
            system("PAUSE");
        break;
        case 7:
            printf("\nGRACIAS POR USAR EL PROGRAMA.\n\n");
        break;
        default:
            printf("\nEsa opcion no esta dentro del menu....\nPor favor escoja de nuevo.\n\n");
            system("PAUSE");
        break;
        }
    }while(opcion!=7);
}

void capturarNombres()
{
    for(i=0;i<VENDEDORES;i++)
    {
        printf("\nVendedor %d : ", i+1);
        fflush(stdin);
        gets(vendedor[i].nombre);
        for(j=0;j<NOMBRE;j++)
            if(vendedor[i].nombre[j]>=97&&vendedor[i].nombre[j]<=122)
                vendedor[i].nombre[j]-=32;
        for(j=0;j<i;j++)
            if(!strcmp(vendedor[j].nombre, vendedor[i].nombre))
            {
                printf("\nEl vendedor ya existe, intente de nuevo");
                i--;
            }
    }
}

void mostrarNombres()
{
    for(i=0;i<VENDEDORES;i++)
    {
        printf("\nVendedor %d : ", i+1);
        printf("%s",vendedor[i].nombre);
    }
}

void leerVendedor()
{
    printf("Ingrese el nombre del vendedor: ");
    do{
        fflush(stdin);
        gets(input);
        for(j=0;j<NOMBRE;j++)
            if(input[j]>=97&&input[j]<=122)
                input[j]-=32;
        fflush(stdin);
        compararVendedor(input);
        if(compararVendedor(input)==-1)
            printf("\nEl vendedor NO existe, intente de nuevo: ");
    }while(compararVendedor(input)<0);
}

void capturarVenta()
{
    int model;
    printf("\nQue modelo se va a vender (1-15)?: ");
    scanf("%d",&model);
    while(model<1||model>MODELOS)
    {
        printf("\nEse modelo NO existe, intente de nuevo: ");
        scanf("%d",&model);
    }
    model--;
    vendedor[compararVendedor(input)].modelo[model]++;
}

void eliminarVenta()
{
    int model;
    printf("\nQue modelo se va a eliminar (1-15)?: ");
    scanf("%d",&model);
    while(model<1||model>MODELOS)
    {
        printf("\nEse modelo NO existe, intente de nuevo: ");
        scanf("%d",&model);
    }
    model--;
    if(vendedor[compararVendedor(input)].modelo[model]>0)
        vendedor[compararVendedor(input)].modelo[model]--;
    else
        printf("\nEl vendedor no tiene ventas de ese modelo\n");
    system("PAUSE");
}

int compararVendedor(char in[NOMBRE])
{
    int x=-1;
    for(i=0;i<VENDEDORES;i++)
    {
        //printf("\n%s = %s\n",in, vendedor[i].nombre);
        if(!strcmp(input, vendedor[i].nombre))
            x=i;
    }
    return x;
}
void mostrarTabla()
{
    printf("Vendedor/Modelo");
    for(i=1;i<=MODELOS;i++)
    {
        printf("| ");
        if(i<10)
            printf(" ");
        printf("%d |",i);
    }
    printf("|Total|");
}

void mostrarMatriz(int x)
{
    printf("\n%s",vendedor[x].nombre);
    len(x);
    int space = 15 - len(x);
    for(i=0;i<space;i++)
        printf(" ");
    for(i=0;i<MODELOS;i++)
    {
        printf("| ");
        if(vendedor[x].modelo[i]<10)
            printf(" ");
        printf("%d |",vendedor[x].modelo[i]);
    }
    for(i=0;i<VENDEDORES;i++)
        vendedor[i].total=0;
    for(i=0;i<MODELOS;i++)
        vendedor[x].total+=vendedor[x].modelo[i];
    printf("| ");
    if(vendedor[x].total<100)
        printf(" ");
    if(vendedor[x].total<10)
        printf(" ");
    printf("%d |",vendedor[x].total);
}

int len(int y)
{
    for(i=0;i<NOMBRE;i++)
    {
        if(vendedor[y].nombre[i]==' '||vendedor[y].nombre[i]=='\0')
            break;
    }
    return i;
}

void totales()
{
    printf("\nTOTAL DE VENTAS");
    for(i=0;i<MODELOS;i++)
        totals[i]=0;
    for(i=0;i<MODELOS;i++)
        for(j=0;j<VENDEDORES;j++)
            totals[i]+=vendedor[j].modelo[i];
    for(i=0;i<MODELOS;i++)
    {
        printf("| ");
        if(totals[i]<10)
            printf(" ");
        printf("%d |",totals[i]);
    }
    for(i=0;i<VENDEDORES;i++)
        FULL_TOTAL+=vendedor[i].total;
    printf("| ");
    if(FULL_TOTAL<100)
        printf(" ");
    if(FULL_TOTAL<10)
        printf(" ");
    printf("%d |",FULL_TOTAL);
}

void ranking(int x)
{
    for(i=0;i<MODELOS;i++)
        totals[i]=0;
    for(i=0;i<VENDEDORES;i++)
        vendedor[i].total=0;
    for(i=0;i<MODELOS;i++)
        for(j=0;j<VENDEDORES;j++)
        {
            totals[i]+=vendedor[j].modelo[i];
            vendedor[j].total+=vendedor[j].modelo[i];
        }
    for(i=0;i<MODELOS;i++)
        copyMod[i]=totals[i];
    for(i=0;i<VENDEDORES;i++)
        copyVend[i]=vendedor[i].total;
    for(i=0;i<x;i++)
    {
        int mayor=0;
        for(j=0;j<x;j++)
        {
            if(x==10)
            {
                if(copyVend[j]>=mayor)
                    mayor=copyVend[j];
            }
            else
                if(copyMod[j]>=mayor)
                    mayor=copyMod[j];
        }
        for(j=0;j<x;j++)
        {
            if(x==10)
            {
                if(copyVend[j]==mayor)
                {
                    copyVend[j]=-1;
                    printf("%d.",i+1);
                    printf("%s: %d autos vendidos\n",vendedor[j].nombre,vendedor[j].total);
                    break;
                }
            }
            else
                if(copyMod[j]==mayor)
                {
                    copyMod[j]=-1;
                    printf("%d.",i+1);
                    printf("Modelo %d: %d ventas\n",j+1,totals[j]);
                    break;
                }
        }
    }
    system("PAUSE");
}

