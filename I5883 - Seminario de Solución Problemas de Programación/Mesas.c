#include <stdio.h>
#include <stdlib.h>
int main (){
    int mm=1,mh=1,lm=1,lh=2,o,a=0,m=0,h=0;
    char nombre[30],sexo;
    do{
        printf("EVENTO DE CARIDAD\n\n%cQu%c Acci%cn desea realizar?",168,130,162);
        printf("\n\n1. Agregar Asistente\n2. Ver Asistentes Agregados\n3. Finalizar\n\nSeleccione una opci%cn: ",162);
        scanf("%d",&o);
        while(o<1||o>3)
        {
            printf("Seleccione una opci%cn v%clida: ",162,160);
            scanf("%d",&o);
        }
        system("cls");
        switch (o)
        {
        case 1:
            printf("Agregar Asistente\n\nSeleccione sexo del asistente Mujer(M) Hombre(H): ");
            fflush(stdin);
            scanf("%c",&sexo);
            while(sexo!='M'&&sexo!='m'&&sexo!='H'&&sexo!='h')
            {
                printf("\nSeleccione una opci%cn v%clida: ",162,160);
                scanf("%c",&sexo);
            }
            printf("\nIngresar nombre del Asistente: \n");
            fflush(stdin);
            gets(nombre);
            system("cls");
            switch (sexo)
            {
            case 'M':
                printf("Nombre del asistente: ");
                puts(nombre);
                if(m<=100)
                    printf("\nEl lugar asisnado es: Mesa %d, Asiento %d\n\n",mm,lm);
                else
                    if(m<=105)
                    printf("\nLos lugares normales se terminaron, pero se pondrá una mesa extra\n\nEl lugar asisnado es: Mesa Extra, Asiento %d\n\n",lm);
                    else
                        printf("L%cmite de lugares Excedido",161);
                lm=lm+2;
                a++;
                m++;
                if(lm>9)
                {
                    lm=1;
                    mm++;
                }
            system("PAUSE");
            system("cls");
            break;
            case 'm':
                printf("Nombre del asistente: ");
                puts(nombre);
                if(m<=100)
                    printf("\nEl lugar asisnado es: Mesa %d, Asiento %d\n\n",mm,lm);
                else
                    if(m<=105)
                    printf("\nLos lugares normales se terminaron, pero se pondrá una mesa extra\n\nEl lugar asisnado es: Mesa Extra, Asiento %d\n\n",lm);
                    else
                        printf("L%cmite de lugares Excedido",161);
                lm=lm+2;
                a++;
                m++;
                if(lm>9)
                {
                    lm=1;
                    mm++;
                }
            system("PAUSE");
            system("cls");
            break;
            case 'H':
                printf("Nombre del asistente: ");
                puts(nombre);
                if(m<=80)
                    printf("\nEl lugar asisnado es: Mesa %d, Asiento %d\n\n",mh,lh);
                else
                    if(m<=84)
                    printf("\nLos lugares normales se terminaron, pero se pondrá una mesa extra\n\nEl lugar asisnado es: Mesa Extra, Asiento %d\n\n",lh);
                    else
                        printf("L%cmite de lugares Excedido",161);
                lh=lh+2;
                a++;
                h++;
                if(lh>9)
                {
                    lh=2;
                    mh++;
                }
            system("PAUSE");
            system("cls");
            break;
            case 'h':
                printf("Nombre del asistente: ");
                puts(nombre);
                if(m<=80)
                    printf("\nEl lugar asisnado es: Mesa %d, Asiento %d\n\n",mh,lh);
                else
                    if(m<=84)
                    printf("\nLos lugares normales se terminaron, pero se pondrá una mesa extra\n\nEl lugar asisnado es: Mesa Extra, Asiento %d\n\n",lh);
                    else
                        printf("L%cmite de lugares Excedido",161);
                lh=lh+2;
                a++;
                h++;
                if(lh>9)
                {
                    lh=2;
                    mh++;
                }
            system("PAUSE");
            system("cls");
            break;
            }
        break;
        default:
            printf("Asistentes Agregados: %d\n",a);
            printf("Mujeres: %d\n",m);
            printf("Hombres: %d\n",h);
            if(m<=20)
            {
                printf("Lugares restantes: %d\n",180-a);
                printf("Lugares para mujeres restantes: %d\n",100-m);
                printf("Lugares para hombres restantes: %d\n\n",80-h);
            }
            else
            {
                printf("Lugares restantes: %d\n",189-a);
                printf("Lugares para mujeres restantes: %d\n",105-m);
                printf("Lugares para hombres restantes: %d\n\n",84-h);
            }
            if(o==2)
            {
                system("PAUSE");
                system("cls");
            }
        }
    }while(o!=3);
}
