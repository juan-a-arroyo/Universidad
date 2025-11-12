/*
Brandon Ariel Ornelas Valadez
Sergio Adrian Guillen López
Fernando José Melendrez Vizcarra
Juan Antonio Arroyo Santana
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int  j, k, contador = 0, respuesta[10],linea[4], mayor, correcta[10], puntos;
    char resp;
    srand(time(NULL));
    do
    {
        respuesta[0,0,0,0,0,0,0,0,0,0];
        correcta[0,0,0,0,0,0,0,0,0,0];
        system("cls");
        for (contador = 1; contador <= 10; contador++)
        {
            printf("CUESTIONARIO\n");
            printf("\nPregunta %d\n", contador);
            printf("Elige la linea mas larga:\n\n");
            mayor = 0;
            for (j = 1; j <= 4; j++)
            {
                printf("%d)", j);
                linea[j] = 1 + rand() % 50;
                while(linea[j]==linea[1]&&j!=1||linea[j]==linea[2]&&j!=2||linea[j]==linea[3]&&j!=3||linea[j]==linea[4]&&j!=4)
                    linea[j] = 1 + rand() % 50;
                for (k = 1; k <= linea[j]; k++)
                {
                    printf("%c",178);
                }
                printf("\n\n");
                if(linea[j] > mayor)
                {
                    correcta[contador] = j;
                    mayor = linea[j];
                }
            }
            printf("R:");
            scanf("%d", &respuesta[contador]);
            while(respuesta[contador]<1||respuesta[contador]>4)
            {
                printf("\nElige una respuesta v%clida: ",160);
                scanf("%d",&respuesta[contador]);
            }
            system("cls");
        }
        puntos = 0;
        for(j=1;j<=10;j++)
        {
            printf("%d = %d\n",respuesta[j],correcta[j]);
            if(respuesta[j]==correcta[j])
                puntos++;
        }
        puntos*=10;
        switch (puntos)
            {
            case 100:
                printf("Felicidades");
            break;
            case 90:
                printf("Muy bien");
            break;
            case 80:
                printf("Bien");
            break;
            case 70:
                printf("A%cn puedes mejorar",150);
            break;
            case 60:
                printf("Sigue intentando");
            break;
            default:
                printf("Intentalo Nuevamente");
            }
        printf("\nTu puntaje total fue de: %d\n\nDeseas intentarlo de nuevo? S%c(S) No(N): ",puntos,161);
        fflush(stdin);
        scanf("%c",&resp);
        while (resp!='s'&&resp!='S'&&resp!='n'&&resp!='N')
            {
                printf("\nElige una respuesta v%clida: ",160);
                fflush(stdin);
                scanf("%c",&resp);
            }
    }while(resp=='s'||resp=='S');
    return 0;
}
