#include <stdio.h>
#include <stdlib.h>
int main(){
    int CODIGO,VOTO=0,A=0,B=0,C=0,TOTAL=0;
    char C_A[20],C_B[20],C_C[20];
    printf("VOTACI%cN DE PRESIDENTE DEL COMIT%c DE ESTUDIANTES\n\n",224,144);
    printf("Inserte nombre del candidato A: ");
    scanf("%s",&C_A);
    printf("Inserte nombre del candidato B: ");
    scanf("%s",&C_B);
    printf("Inserte nombre del candidato C: ");
    scanf("%s",&C_C);
    system("cls");
    do{
        CODIGO=0;
        printf("VOTACI%cN DE PRESIDENTE DEL COMIT%c DE ESTUDIANTES\n\n",224,144);
        printf("Inserte su c%cdigo: ",162);
        scanf("%d",&CODIGO);
        system("cls");
        if(CODIGO!=7383120)
        {
            printf("VOTACI%cN DE PRESIDENTE DEL COMIT%c DE ESTUDIANTES\n\n",224,144);
            printf("Candidatos:\n\n");
            printf("1.%s\n2.%s\n3.%s\n\n",C_A,C_B,C_C);
            printf("Elige un candidato: ");
            do{
                scanf("%d",&VOTO);
                switch (VOTO)
                {
                case 1:
                    A++;
                    system("cls");
                break;
                case 2:
                    B++;
                    system("cls");
                break;
                case 3:
                    C++;
                    system("cls");
                break;
                default:
                    printf("Inserte un candidato v%clido: ",160);
                }
            }while(VOTO!=1&&VOTO!=2&&VOTO!=3);
        }
    system("cls");
    }while(CODIGO!=7383120);
    TOTAL=A+B+C;
    printf("El total de votos fue: %d\n\n",TOTAL);
    printf("Los resultados son:\n\n1.%s: %d votos\n2.%s %d votos\n1.%s %d votos\n",C_A,A,C_B,B,C_C,C);
    return 0;
}
