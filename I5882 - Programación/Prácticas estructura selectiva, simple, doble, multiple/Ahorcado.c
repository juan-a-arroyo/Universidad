#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ()
{
/*
        -------------
        |           |
        |           _
        |         ( _ )
        |          _|_
        |           |
        |          / \
        |
        |
-----------------

PROGRAMA
COMPILADOR
VARIABLE
PROCESADOR
MEMORIA
CODIGO
*/
    int i, j, errores=0, err=0, palab, x;
    char palabra[10], juego[10], letra, GAME;
    srand(time(NULL));
    do{
        palab=1+rand() % 5;
        switch (palab)
        {
        case 1:
            palabra[0]='P';
            palabra[1]='R';
            palabra[2]='O';
            palabra[3]='G';
            palabra[4]='R';
            palabra[5]='A';
            palabra[6]='M';
            palabra[7]='A';
            palabra[8]=' ';
            palabra[9]=' ';
            juego[8]=' ';
            juego[9]=' ';
        break;
        case 2:
            palabra[0]='C';
            palabra[1]='O';
            palabra[2]='M';
            palabra[3]='P';
            palabra[4]='I';
            palabra[5]='L';
            palabra[6]='A';
            palabra[7]='D';
            palabra[8]='O';
            palabra[9]='R';
        break;
        case 3:
            palabra[0]='V';
            palabra[1]='A';
            palabra[2]='R';
            palabra[3]='I';
            palabra[4]='A';
            palabra[5]='B';
            palabra[6]='L';
            palabra[7]='E';
            palabra[8]=' ';
            palabra[9]=' ';
            juego[8]=' ';
            juego[9]=' ';
        break;
        case 4:
            palabra[0]='P';
            palabra[1]='R';
            palabra[2]='O';
            palabra[3]='C';
            palabra[4]='E';
            palabra[5]='S';
            palabra[6]='A';
            palabra[7]='D';
            palabra[8]='O';
            palabra[9]='R';
        break;
        case 5:
            palabra[0]='M';
            palabra[1]='E';
            palabra[2]='M';
            palabra[3]='O';
            palabra[4]='R';
            palabra[5]='I';
            palabra[6]='A';
            palabra[7]=' ';
            palabra[8]=' ';
            palabra[9]=' ';
            juego[7]=' ';
            juego[8]=' ';
            juego[9]=' ';
        break;
        case 6:
            palabra[0]='C';
            palabra[1]='O';
            palabra[2]='D';
            palabra[3]='I';
            palabra[4]='G';
            palabra[5]='O';
            palabra[6]=' ';
            palabra[7]=' ';
            palabra[8]=' ';
            palabra[9]=' ';
            juego[6]=' ';
            juego[7]=' ';
            juego[8]=' ';
            juego[9]=' ';
        break;
        }
        for(i=0; i<10; i++)
            {
                x = rand() %100;
                x = rand() %x;
                if (x%2==0)
                    juego[i] = palabra[i];
                else
                    juego[i]=' ';
            }
        while(errores<=8)
        {
            system("cls");
            printf("AHORCADO\n\nERRORES: %d\n\n",errores);
            for (i=1; i<=10; i++)
            {
                if (i<10)
                {
                    if (errores>=2)
                    {
                        printf ("\t");
                        if (i>1)
                            printf ("|");
                    }
                    switch (i)
                    {
                    case 1:
                        if (errores>=3)
                            for (j=1; j<=10; j++)
                                printf ("-");
                    break;
                    case 2:
                        if (errores>=4)
                            printf ("\t |");
                    break;
                    case 3:
                        if (errores>=5)
                            printf ("\t _");
                    break;
                    case 4:
                        if (errores>=5)
                            printf ("      ( _ )");
                    break;
                    case 5:
                        if (errores==6)
                            printf ("        | ");
                        if (errores>=7)
                            printf ("       _|_");
                    break;
                    case 6:
                        if (errores>=6)
                            printf ("        | ");
                    break;
                    case 7:
                        if (errores>=8)
                        printf ("       / %c",92);
                    break;
                    }
                }
                else
                    if (errores>=1)
                        for(j=1; j<=17; j++)
                            printf ("-");
                printf ("\n");
            }
            for(i=0; i<10; i++)
            {
                printf("%c",juego[i]);
            }
            printf("\n\nEscriba una letra: ");
            fflush(stdin);
            scanf("%c",&letra);
            for(i=0; i<10; i++)
            {
                if (letra==palabra[i]&&letra!=juego[i])
                    juego[i]=palabra [i];
                else
                    err++;
            }
            if (err==10)
                errores++;
            err=0;
            if(juego[0]==palabra[0]&&juego[1]==palabra[1]&&juego[2]==palabra[2]&&juego[3]==palabra[3]&&juego[4]==palabra[4]&&juego[5]==palabra[5]&&juego[6]==palabra[6]&&juego[7]==palabra[7]&&juego[8]==palabra[8]&&juego[9]==palabra[9])
                break;
        }
        if(juego[0]==palabra[0]&&juego[1]==palabra[1]&&juego[2]==palabra[2]&&juego[3]==palabra[3]&&juego[4]==palabra[4]&&juego[5]==palabra[5]&&juego[6]==palabra[6]&&juego[7]==palabra[7]&&juego[8]==palabra[8]&&juego[9]==palabra[9])
            printf("GANASTE");
        else
            printf("PERDISTE");
        printf("\n\nQuieres jugar de nuevo? Si(S) No(N): ");
        fflush(stdin);
        scanf("%c",&GAME);
        if(GAME=='S'||GAME=='s')
            system("cls");
    }while(GAME=='S'||GAME=='s');
    return 0;
}
