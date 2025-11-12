#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int inicial[10],i,valor,articulos=0,moneda,opc,dinero,cambio[10],corte[10],cantidad;
    float total=0,monto;
    //INGRESO DE EFECTIVO
    printf("CAJA REGISTRADORA\n\n");
    printf("Ingreso de Dinero: \n\n");
    for(i=0;i<10;i++)
    {
        printf("Ingrese ");
        if(i<5)
            printf("Billetes de ");
        else
            printf("Monedas de ");
        switch (i)
        {
        case 0:
            printf("500 ");
        break;
        case 1:
            printf("200 ");
        break;
        case 2:
            printf("100 ");
        break;
        case 3:
            printf("50 ");
        break;
        case 4:
            printf("20 ");
        break;
        case 5:
            printf("10 ");
        break;
        case 6:
            printf("5 ");
        break;
        case 7:
            printf("2 ");
        break;
        case 8:
            printf("1 ");
        break;
        case 9:
            printf("50 ");
        break;
        }
        if(i==9)
            printf("centavos: ");
        else
            printf("pesos: ");
        scanf("%d",&inicial[i]);
        corte[i]=inicial[i];
    }
    printf("\n\n");

    //SUMA DEL TOTAL INICIAL
    for(i=0;i<10;i++)
        switch (i)
        {
        case 0:
            total=total+500*inicial[i];
        break;
        case 1:
            total=total+200*inicial[i];
        break;
        case 2:
            total=total+100*inicial[i];
        break;
        case 3:
            total=total+50*inicial[i];
        break;
        case 4:
            total=total+20*inicial[i];
        break;
        case 5:
            total=total+10*inicial[i];
        break;
        case 6:
            total=total+5*inicial[i];
        break;
        case 7:
            total=total+2*inicial[i];
        break;
        case 8:
            total=total+inicial[i];
        break;
        case 9:
            total=total+.50*inicial[i];
        break;
        }
        printf("El Total inicial es: $%.2f\n\n",total);
        system("PAUSE");
        system("cls");
        //MENU
        do{
            system("cls");
            printf("TIENDA DE ABARROTES\n\n1.Realizar una venta\n2.Dinero en caja\n3.Realizar Corte de caja");
            printf("\n\nIngrese una opcion: ");
            scanf("%d",&opc);
            switch(opc)
            {
            case 1:
                system("cls");
                printf("VENTA\n\nIngrese el monto del Articulo: ");
                scanf("%f",&monto);
                printf("Ingrese el dinero a pagar: ");
                scanf("%d",&dinero);
                //RESTA DE DINERO ENTREGADO
                moneda=dinero-monto;
                corte[0]-=moneda/500;
                moneda=moneda%500;
                corte[1]-=moneda/200;
                moneda=moneda%200;
                corte[2]-=moneda/100;
                moneda=moneda%100;
                corte[3]-=moneda/50;
                moneda=moneda%50;
                corte[4]-=moneda/20;
                moneda=moneda%20;
                corte[5]-=moneda/10;
                moneda=moneda%10;
                corte[6]-=moneda/5;
                moneda=moneda%5;
                corte[7]-=moneda/2;
                moneda=moneda%2;
                corte[8]-=moneda/1;
                moneda=moneda%1;
                corte[9]-=moneda/.5;

                //CAMBIO ENTREGADO AL CLIENTE
                moneda=dinero-monto;
                cambio[0]=moneda/500;
                moneda=moneda%500;
                cambio[1]=moneda/200;
                moneda=moneda%200;
                cambio[2]=moneda/100;
                moneda=moneda%100;
                cambio[3]=moneda/50;
                moneda=moneda%50;
                cambio[4]=moneda/20;
                moneda=moneda%20;
                cambio[5]=moneda/10;
                moneda=moneda%10;
                cambio[6]=moneda/5;
                moneda=moneda%5;
                cambio[7]=moneda/2;
                moneda=moneda%2;
                cambio[8]=moneda/1;
                moneda=moneda%1;
                cambio[9]=moneda/.5;

                //SUMA DE DINERO RECIBIDO
                corte[0]+=dinero/500;
                dinero=dinero%500;
                corte[1]+=dinero/200;
                dinero=dinero%200;
                corte[2]+=dinero/100;
                dinero=dinero%100;
                corte[3]+=dinero/50;
                dinero=dinero%50;
                corte[4]+=dinero/20;
                dinero=dinero%20;
                corte[5]+=dinero/10;
                dinero=dinero%10;
                corte[6]+=dinero/5;
                dinero=dinero%5;
                corte[7]+=dinero/2;
                dinero=dinero%2;
                corte[8]+=dinero/1;
                dinero=dinero%1;
                corte[9]+=dinero/.5;

                articulos++;

                printf("\n\nCambio a entregar: \n");
                for(i=0;i<10;i++)
                {
                    if(cambio[i]>0)
                    {
                        switch(i)
                        {
                        case 0:
                            printf("500 ");
                        break;
                        case 1:
                            printf("200 ");
                        break;
                        case 2:
                            printf("100 ");
                        break;
                        case 3:
                            printf("50 ");
                        break;
                        case 4:
                            printf("20 ");
                        break;
                        case 5:
                            printf("10 ");
                        break;
                        case 6:
                            printf("5 ");
                        break;
                        case 7:
                            printf("2 ");
                        break;
                        case 8:
                            printf("1 ");
                        break;
                        case 9:
                            printf("50 ");
                        break;
                        }
                        if(i==9)
                            printf("centavos: ");
                        else
                            printf("pesos: ");
                        printf("%d\n",cambio[i]);
                    }
                }
                system("PAUSE");
            break;
            case 2:
                system("cls");
                printf("Dinero en Caja:\n\n");
                for(i=0;i<10;i++)
                {
                    switch(i)
                    {
                    case 0:
                        printf("500 ");
                    break;
                    case 1:
                        printf("200 ");
                    break;
                    case 2:
                        printf("100 ");
                    break;
                    case 3:
                        printf("50 ");
                    break;
                    case 4:
                        printf("20 ");
                    break;
                    case 5:
                        printf("10 ");
                    break;
                    case 6:
                        printf("5 ");
                    break;
                    case 7:
                        printf("2 ");
                    break;
                    case 8:
                        printf("1 ");
                    break;
                    case 9:
                        printf("50 ");
                    break;
                    }
                    if(i==9)
                        printf("centavos: ");
                    else
                        printf("pesos: ");
                    printf("%d\n",corte[i]);
                }
                system("PAUSE");
            break;
            case 3:
                system("cls");
                printf("CORTE DE CAJA\n\n");
                printf("Ventas realizadas: %d\n\n",articulos);
                printf("Dinero en Caja:\n\n");
                for(i=0;i<10;i++)
                {
                    switch(i)
                    {
                    case 0:
                        printf("500 ");
                    break;
                    case 1:
                        printf("200 ");
                    break;
                    case 2:
                        printf("100 ");
                    break;
                    case 3:
                        printf("50 ");
                    break;
                    case 4:
                        printf("20 ");
                    break;
                    case 5:
                        printf("10 ");
                    break;
                    case 6:
                        printf("5 ");
                    break;
                    case 7:
                        printf("2 ");
                    break;
                    case 8:
                        printf("1 ");
                    break;
                    case 9:
                        printf("50 ");
                    break;
                    }
                    if(i==9)
                        printf("centavos: ");
                    else
                        printf("pesos: ");
                    printf("%d\n",corte[i]);
                }
                printf("\n\nCAJA CERRADA\n\n");
            break;
            }
        }while(opc!=3);
    return 0;
}
