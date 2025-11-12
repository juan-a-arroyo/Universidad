/*
Juan Antonio Arroyo Santana - INNI (220792779)
Realice un programa que presente 10 preguntas las cuales serán resueltas por un niño de 3er grado,  las preguntas deben mostrar 4 líneas de diferente tamaño y debe enunciar "Elige la  X línea más larga"  donde X puede ser tomar el valor de "la segunda", "la tercera", "la más" y tambien puede cambiar las palabras Línea más larga por Línea más corta.
Vea la imagen anexa para que sea mas claro.
El programa debe sumar aciertos mostrando al final la cantidad de acierto como por ejemplo  Felicidades sacaste 10/10 aciertos  y obtuviste 100 puntos.


NOTA: las líneas las puede dibujar el carácter (alt+178).
cada acierto vale 10 puntos.
conforme baje la cantidad de aciertos el mensaje debe cambiar.

para 100 puntos  "Felicidades "
para 90 puntos "Muy bien"
para 80 puntos "Bien"
para 70 puntos "Aún puedes mejorar "
para 60 puntos "Sigue intentando"
y para 50 o menos puntos "Inténtalo nuevamente"
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int PUNTOS=0,LINEA=0,PREGUNTA=0;
    char CONTINUAR;
    while(PREGUNTA==0)
    {
        CONTINUAR=0;
        PREGUNTA=1;
        while (PREGUNTA<=10)
        {
            LINEA=0;
            printf("Observa las l%cneas y responde: \n",161);
            printf("\n1. %c%c%c%c%c%c%c%c%c%c%c%c\n",178,178,178,178,178,178,178,178,178,178,178,178);
            printf("\n2. %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178,178);
            printf("\n3. %c%c%c%c%c%c%c%c%c%c\n",178,178,178,178,178,178,178,178,178,178);
            printf("\n4. %c%c%c%c%c\n",178,178,178,178,178);
            printf("\n%d. ",PREGUNTA);
            switch (PREGUNTA)
            {
            case 1:
                printf("Elige la l%cnea m%cs larga: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==2)
                    PUNTOS=PUNTOS+10;
            PREGUNTA=PREGUNTA+1;
            break;
            case 2:
                printf("Elige la segunda l%cnea m%cs larga: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==1)
                    PUNTOS=PUNTOS+10;
                PREGUNTA=PREGUNTA+1;
                break;
                case 3:
                printf("Elige la l%cnea m%cs corta: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==4)
                    PUNTOS=PUNTOS+10;
            PREGUNTA=PREGUNTA+1;
            break;
            case 4:
                printf("Elige la tercera l%cnea m%cs larga: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==3)
                    PUNTOS=PUNTOS+10;
            PREGUNTA=PREGUNTA+1;
            break;
            case 5:
                printf("Elige la segunda l%cnea m%cs corta: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==3)
                    PUNTOS=PUNTOS+10;
            PREGUNTA=PREGUNTA+1;
            break;
            case 6:
                printf("Elige la cuarta l%cnea m%cs larga: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==4)
                    PUNTOS=PUNTOS+10;
            PREGUNTA=PREGUNTA+1;
            break;
            case 7:
                printf("Elige la cuarta l%cnea m%cs corta: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==2)
                    PUNTOS=PUNTOS+10;
            PREGUNTA=PREGUNTA+1;
            break;
            case 8:
                printf("Elige la tercera l%cnea m%cs corta: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==1)
                    PUNTOS=PUNTOS+10;
            PREGUNTA=PREGUNTA+1;
            break;
            case 9:
                printf("Elige la l%cnea menos larga: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==4)
                    PUNTOS=PUNTOS+10;
            PREGUNTA=PREGUNTA+1;
            break;
            case 10:
                printf("Elige la l%cnea menos corta: ",161,160);
                scanf("%d",&LINEA);
                while (LINEA<1||LINEA>4)
                {
                    printf("\nElige una respuesta v%clida: ",160);
                    scanf("%d",&LINEA);
                }
                if(LINEA==2)
                    PUNTOS=PUNTOS+10;
            PREGUNTA=PREGUNTA+1;
            break;
            }
        system("PAUSE");
        system("cls");
        }
        switch (PUNTOS)
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
        printf(", obtuviste %d\n",PUNTOS);
        if (PUNTOS<60)
        {
            printf("%cDeseas intentarlo nuevamente? S%c(Y) No(N): ",168,161);
            fflush(stdin);
            scanf("%c",&CONTINUAR);
            switch(CONTINUAR)
            {
            case 'Y':
                PREGUNTA=0;
                PUNTOS=0;
                system("PAUSE");
                system("cls");
            break;
            case 'y':
                PREGUNTA=0;
                PUNTOS=0;
                system("PAUSE");
                system("cls");
            break;
            }
        }
    }
    return 0;
}
