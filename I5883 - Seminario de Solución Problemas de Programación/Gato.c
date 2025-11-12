#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int main()
{
/*
X|X|X
O|O|O
X|X|X
*/
    int i, j, X, Y, WIN, EMP;
    char opc, PL, IA, GAME;
    srand(time(NULL));
    do{
        WIN=0;
        EMP=0;
        char gato[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
        printf("JUEGO GATO\n\n");
        do{
            printf("\nElige X o O: ");
            fflush(stdin);
            scanf("%c",&opc);
        }while(opc!='X'&&opc!='x'&&opc!='O'&&opc!='o');
        if(opc=='X'||opc=='x')
        {
            PL='X';
            IA='O';
        }
        else
        {
            PL='O';
            IA='X';
        }
        system("cls");
        while(WIN==0&&EMP<9)
        {
            printf("JUEGO GATO\n\n");
            for(i=0; i<3; i++)
            {
                printf("    ");
                for(j=0; j<3; j++)
                {
                    printf("%c",gato[i][j]);
                    if (j<2)
                        printf("|");
                }
                printf("\n");
            }
            //JUGADOR
            do{
            printf("\nElige una coordenada (1,3): ");
            scanf("%d %d",&X, &Y);
            }while(X<=0||X>3&&Y<=0||Y>3);
            if(gato[X-1][Y-1]==' ')
                gato[X-1][Y-1]=PL;
            else
                do{
                    printf("\n\nCelda Ocupada, Elige Otra; ");
                    scanf("%d %d",&X, &Y);
                }while(gato[X-1][Y-1]!=' ');
            system("cls");
            //IA
            EMP=0;
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    if(gato[i][j]!=' ')
                        EMP++;
            if(EMP<9)
            {
                do{
                X = rand() %4;
                Y = rand() %4;
                }while(gato[X-1][Y-1]!=' ');
                gato[X-1][Y-1]=IA;
            }
            //EVAL
            if(gato[0][0]==gato[0][1]&&gato[0][1]==gato[0][2]&&gato[0][0]!=' ')
            {
                if(gato[0][0]==PL)
                {
                    printf("GANASTE");
                    WIN=1;
                }
                else
                {
                    printf("PERDISTE");
                    WIN=2;
                }
            }
            else
                if(gato[1][0]==gato[1][1]&&gato[1][1]==gato[1][2]&&gato[1][0]!=' ')
                {
                    if(gato[1][0]==PL)
                    {
                        printf("GANASTE");
                        WIN=1;
                    }
                    else
                    {
                        printf("PERDISTE");
                        WIN=2;
                    }
                }
                else
                    if(gato[2][0]==gato[2][1]&&gato[2][1]==gato[2][3]&&gato[2][0]!=' ')
                    {
                        if(gato[2][0]==PL)
                        {
                            printf("GANASTE");
                            WIN=1;
                        }
                        else
                        {
                            printf("PERDISTE");
                            WIN=2;
                        }
                    }
                    else
                        if(gato[0][0]==gato[1][0]&&gato[1][0]==gato[2][0]&&gato[0][0]!=' ')
                        {
                            if(gato[0][0]==PL)
                            {
                                printf("GANASTE");
                                WIN=1;
                            }
                            else
                            {
                                printf("PERDISTE");
                                WIN=2;
                            }
                        }
                        else
                            if(gato[0][1]==gato[1][1]&&gato[1][1]==gato[2][1]&&gato[0][1]!=' ')
                            {
                                if(gato[0][1]==PL)
                                {
                                    printf("GANASTE");
                                    WIN=1;
                                }
                                else
                                {
                                    printf("PERDISTE");
                                    WIN=2;
                                }
                            }
                            else
                                if(gato[0][2]==gato[1][2]&&gato[1][2]==gato[2][2]&&gato[0][2]!=' ')
                                {
                                    if(gato[0][2]==PL)
                                    {
                                        printf("GANASTE");
                                        WIN=1;
                                    }
                                    else
                                    {
                                        printf("PERDISTE");
                                        WIN=2;
                                    }
                                }
                                else
                                    if(gato[0][0]==gato[1][1]&&gato[1][1]==gato[2][2]&&gato[0][0]!=' ')
                                    {
                                        if(gato[0][0]==PL)
                                        {
                                            printf("GANASTE");
                                            WIN=1;
                                        }
                                        else
                                        {
                                            printf("PERDISTE");
                                            WIN=2;
                                        }
                                    }
                                    else
                                        if(gato[2][0]==gato[1][1]&&gato[1][1]==gato[0][2]&&gato[2][0]!=' ')
                                        {
                                            if(gato[2][0]==PL)
                                            {
                                                printf("GANASTE");
                                                WIN=1;
                                            }
                                            else
                                            {
                                                printf("PERDISTE");
                                                WIN=2;
                                            }
                                        }
            if(EMP==9)
                printf("EMPATE");
        }
        printf("\n\n");
        for(i=0; i<3; i++)
        {
            printf("    ");
            for(j=0; j<3; j++)
            {
                printf("%c",gato[i][j]);
                if (j<2)
                    printf("|");
            }
            printf("\n");
        }
        printf("\n\nQuieres jugar de nuevo? Si(S) No(N): ");
        fflush(stdin);
        scanf("%c",&GAME);
        if(GAME=='S'||GAME=='s')
            system("cls");
    }while(GAME=='S'||GAME=='s');
    system("PAUSE");
    return 0;
}
