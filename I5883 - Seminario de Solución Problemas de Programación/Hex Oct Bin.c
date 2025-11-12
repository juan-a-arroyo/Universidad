#include <stdio.h>
#include <stdlib.h>
int main (){
    int opcion,num,numero[50],dividendo,residuo,i,band=0;
    do{
        for(i=0;i<50;i++)
            numero[i]=0;
            system("cls");
        printf("CONVERSOR DE BINARIO A BASE\n\n");
        printf("%cA qu%c base desea convertir?\n",168,130);
        printf("\n1.Base 2 (Binario)\n2.Base 8 (Octal)\n3.Base 16 (Hexadecimal)\n4.Salir\n\nSeleccione una opci%cn: ",162);
        scanf("%d",&opcion);
        while(opcion<1||opcion>4)
        {
            printf("Seleccione una opci%cn v%clida: ",162,160);
            scanf("%d",&opcion);
        }
        switch (opcion)
        {
        case 1:
            dividendo=2;
        break;
        case 2:
            dividendo=8;
        break;
        case 3:
            dividendo=16;
        break;
        }
        if(opcion>0&&opcion<4)
        {
            printf("\n%cQu%c n%cmero desea convertir?: ",168,130,163);
            scanf("%d",&num);
            //for(i=num;i>=dividendo;i=num/dividendo)
            for(i=0;i<50;i++)
            {
                numero[i]=num%dividendo;
                num=num/dividendo;
            }
            for(i=49;i>=0;i--)
            {
                if(numero[i]!=0)
                    band=1;
                if(band==1)
                    if(numero[i]<10)
                        printf("%d",numero[i]);
                    else
                        switch (numero[i])
                        {
                        case 10:
                            printf("A");
                        break;
                        case 11:
                            printf("B");
                        break;
                        case 12:
                            printf("C");
                        break;
                        case 13:
                            printf("D");
                        break;
                        case 14:
                            printf("E");
                        break;
                        case 15:
                            printf("F");
                        break;
                        }
            }
            band=0;
        }
        printf("\n");
        system("PAUSE");
    }while(opcion!=4);
    return 0;
}
