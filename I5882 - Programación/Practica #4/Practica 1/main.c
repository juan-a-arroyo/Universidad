#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char gato[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    char resp, sel,IA,turn,vic=0,der=0,emp=0;
    int i,j,x,y,fil,col,band=0;

    do{
        system("CLS");
        band=0;
        for(fil=0;fil<3;fil++)
            for(col=0;col<3;col++)
            gato[fil][col]='-';

        printf("\t\t\tJuego Gato!!\n\n");
        printf("Victorias: %d\n",vic);
        printf("Derrotas: %d\n",der);
        printf("Empates: %d\n\n",emp);

        //Seleccionar el dato
        do{
        printf("Elige X o 0:\n");
        fflush(stdin);
        scanf("%c",&sel);
        }while (sel!='X' && sel!='0');

        if(sel=='X')
        {
           IA='0';
        }
        else
        {
           IA='X';
        }

        //turnos del Juego
        for(turn=0;turn<9;turn++)
        {
            system("CLS");

            printf("\t\t\tJuego Gato!!\n\n");
            printf("Turno del Jugador\n");
            do{
            printf("Ingresa la cordenada [X][Y]:\n");
            scanf("%d %d",&x,&y);
            }while(gato[x][y]!='-');

            gato[x][y]=sel;

            do{
            x=rand() %3;
            y=rand() %3;
            printf("%d %d\n",x,y);
            printf("%d",turn);
            system("pause");
            if (turn==4)
                break;
            }while(gato[x][y]!='-');
            if (turn!=4)
                gato[x][y]=IA;

            //Imprime matriz
            for(i=0;i<3;i++)
            {
                printf("\t");
                for(j=0;j<3;j++)
                {
                    printf("%c ",gato[i][j]);
                    if(j<2)
                        printf("|");
                }
                 printf("\n");
                if(i<2)
                    printf("\t________");
                printf("\n");

            }

            //¿Ganador?
            if((gato[0][0]==sel && gato[0][1]==sel && gato[0][2]==sel)||(gato[1][0]==sel && gato[1][1]==sel && gato[1][2]==sel) || (gato[2][0]==sel && gato[2][1]==sel && gato[2][2]==sel))
            {
                printf("Haz ganado!!\n");
                vic++;
                break;
            }
            if((gato[0][0]==IA && gato[0][1]==IA && gato[0][2]==IA)||(gato[1][0]==IA && gato[1][1]==IA && gato[1][2]==IA) || (gato[2][0]==IA && gato[2][1]==IA && gato[2][2]==IA))
            {
                printf("Haz Perdido!!\n");
                der++;
                break;
            }

            if((gato[0][0]==sel && gato[1][0]==sel && gato[2][0]==sel)||(gato[2][1]==sel && gato[0][1]==sel && gato[1][1]==sel)||(gato[0][2]==sel && gato[1][2]==sel && gato[2][2]==sel))
               {
                printf("Haz ganado!!\n");
                vic++;
                break;
               }
            if((gato[0][0]==IA && gato[1][0]==IA && gato[2][0]==IA)||(gato[2][1]==IA && gato[0][1]==IA && gato[1][1]==IA)||(gato[0][2]==IA && gato[1][2]==IA && gato[2][2]==IA))
               {
                printf("Haz Perdido!!\n");
                der++;
                break;
               }
               if((gato[0][0]==sel && gato[1][1]==sel && gato[2][2]==sel) ||(gato[0][2]==sel && gato[1][1]==sel && gato[2][0]==sel))
                {
                printf("Haz ganado!!\n");
                vic++;
                break;
                }
               if((gato[0][0]==IA && gato[1][1]==IA && gato[2][2]==IA) ||(gato[0][2]==IA && gato[1][1]==IA && gato[2][0]==IA))
                {
                printf("Haz perdido!!\n");
                der++;
                break;
                }

            system("Pause");

        }





        //Iniciar otro juego
        printf("Desea jugar otra partida (s) Si o (n) No\n");
        fflush(stdin);
        scanf("%c",&resp);
    }while(resp=='s' || resp =='S');
    return 0;
}
