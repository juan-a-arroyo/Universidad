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

struct venta
{
    char nombre[NOMBRE];
    int modelo[MODELOS];
    int total;
}vendedor[VENDEDORES];

struct venta vendedor[VENDEDORES]={};

int compararVendedor();
int len();
void totales();

int main()
{
    int x, i, j, k, opcion, model, FULL_TOTAL=0, totals[MODELOS]={},copyVend[VENDEDORES],copyMod[MODELOS];
    char input[NOMBRE];
    printf("AGENCIA DE VENTA DE VEHICULOS.\n\n");
    printf("Debera Ingresar el nombre de los 10 vendedores.\n");
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
            for(i=0;i<VENDEDORES;i++)
            {
                printf("\nVendedor %d : ", i+1);
                printf("%s",vendedor[i].nombre);
            }
            system("PAUSE");
        break;
        case 1:
            system("cls");
            printf("Capturar una venta.\n\n");
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
            printf("\nQue modelo se va a vender (1-15)?: ");
            scanf("%d",&model);
            while(model<1||model>MODELOS)
            {
                printf("\nEse modelo NO existe, intente de nuevo: ");
                scanf("%d",&model);
            }
            model--;
            vendedor[compararVendedor(input)].modelo[model]++;
        break;
        case 2:
            system("cls");
            printf("Ranking de vendedores.\n\n");
            for(i=0;i<VENDEDORES;i++)
                vendedor[i].total=0;
            for(i=0;i<MODELOS;i++)
                for(j=0;j<VENDEDORES;j++)
                    vendedor[j].total+=vendedor[j].modelo[i];
            for(i=0;i<VENDEDORES;i++)
                copyVend[i]=vendedor[i].total;
            for(i=0;i<VENDEDORES;i++)
            {
                int mayor=0;
                for(j=0;j<VENDEDORES;j++)
                    if(copyVend[j]>=mayor)
                        mayor=copyVend[j];
                for(j=0;j<VENDEDORES;j++)
                        if(copyVend[j]==mayor)
                        {
                            copyVend[j]=-1;
                            printf("%d.",i+1);
                            printf("%s: %d autos vendidos\n",vendedor[j].nombre,vendedor[j].total);
                            break;
                        }
            }
            system("PAUSE");
        break;
        case 3:
            system("cls");
            printf("Eliminar una venta.\n\n");
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

        break;
        case 4:
            system("cls");
            printf("Buscar vendedor.\n\n");
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
            printf("Vendedor/Modelo");
            for(i=1;i<=MODELOS;i++)
            {
                printf("| ");
                if(i<10)
                    printf(" ");
                printf("%d |",i);
            }
            printf("|Total|");
            printf("\n%s",vendedor[compararVendedor(input)].nombre);
            for(j=0;j<NOMBRE;j++)
            {
                if(vendedor[compararVendedor(input)].nombre[j]==' '||vendedor[compararVendedor(input)].nombre[j]=='\0')
                    break;
            }
            int space = 15 - j;
            for(i=0;i<space;i++)
                printf(" ");
            for(j=0;j<MODELOS;j++)
            {
                printf("| ");
                if(vendedor[compararVendedor(input)].modelo[j]<10)
                    printf(" ");
                printf("%d |",vendedor[compararVendedor(input)].modelo[j]);
            }
            for(j=0;j<VENDEDORES;j++)
                vendedor[j].total=0;
            for(j=0;j<MODELOS;j++)
                vendedor[compararVendedor(input)].total+=vendedor[compararVendedor(input)].modelo[j];
            printf("| ");
            if(vendedor[compararVendedor(input)].total<100)
                printf(" ");
            if(vendedor[compararVendedor(input)].total<10)
                printf(" ");
            printf("%d |",vendedor[compararVendedor(input)].total);
            printf("\n");
            system("PAUSE");
        break;
        case 5:
            system("cls");
            printf("Lista de modelos de auto mas vendidos.\n\n");
            for(i=0;i<MODELOS;i++)
                totals[i]=0;
            for(i=0;i<MODELOS;i++)
                for(j=0;j<VENDEDORES;j++)
                    totals[i]+=vendedor[j].modelo[i];;
            for(i=0;i<MODELOS;i++)
                copyMod[i]=totals[i];
            for(i=0;i<MODELOS;i++)
            {
                int mayor=0;
                for(j=0;j<MODELOS;j++)
                    if(copyMod[j]>=mayor)
                        mayor=copyMod[j];
                for(j=0;j<MODELOS;j++)
                        if(copyMod[j]==mayor)
                        {
                            copyMod[j]=-1;
                            printf("%d.",i+1);
                            printf("Modelo %d: %d ventas\n",j+1,totals[j]);
                            break;
                        }
            }
            system("PAUSE");
        break;
        case 6:
            system("cls");
            printf("Informe mensual.\n\n");
                printf("Vendedor/Modelo");
            for(i=1;i<=MODELOS;i++)
            {
                printf("| ");
                if(i<10)
                    printf(" ");
                printf("%d |",i);
            }
            printf("|Total|");
            for(k=0;k<VENDEDORES;k++)
            {
                printf("\n%s",vendedor[k].nombre);
                for(j=0;j<NOMBRE;j++)
                {
                    if(vendedor[k].nombre[j]==' '||vendedor[k].nombre[j]=='\0')
                        break;
                }
                int space = 15 - j;
                for(j=0;j<space;j++)
                    printf(" ");
                for(j=0;j<MODELOS;j++)
                {
                    printf("| ");
                    if(vendedor[k].modelo[j]<10)
                        printf(" ");
                    printf("%d |",vendedor[k].modelo[j]);
                }
                for(j=0;j<VENDEDORES;j++)
                    vendedor[j].total=0;
                for(j=0;j<MODELOS;j++)
                    vendedor[k].total+=vendedor[k].modelo[j];
                printf("| ");
                if(vendedor[k].total<100)
                    printf(" ");
                if(vendedor[k].total<10)
                    printf(" ");
                printf("%d |",vendedor[k].total);
            }
            printf("\nTOTAL DE VENTAS");
            for(i=0;i<MODELOS;i++)
                totals[i]=0;
            for(i=0;i<MODELOS;i++)
                for(j=0;j<VENDEDORES;j++)
                    totals[i]+=vendedor[j].modelo[i];
            FULL_TOTAL=0;
            for(j=0;j<MODELOS;j++)
                FULL_TOTAL+=totals[j];
            for(i=0;i<MODELOS;i++)
            {
                printf("| ");
                if(totals[i]<10)
                    printf(" ");
                printf("%d |",totals[i]);
            }
            printf("| ");
            if(FULL_TOTAL<100)
                printf(" ");
            if(FULL_TOTAL<10)
                printf(" ");
            printf("%d |",FULL_TOTAL);
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


int compararVendedor(char in[NOMBRE])
{
    int x=-1,i;
    for(i=0;i<VENDEDORES;i++)
    {
        if(!strcmp(in, vendedor[i].nombre))
            x=i;
    }
    return x;
}
