#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int A[10],B[10],C[10],opc,i,neg;
    char vector;
    srand(time(NULL));
    do{
        system("cls");
        printf("VECTORES\n\n");
        printf("1.Llenar vector A de manera aleatoria\n2.Llenar vector B de manera aleatoria\n3.Realizar C=A+B\n4.Realizar C=B-A\n5.Mostrar\n6.Salir");
        printf("\n\nSeleccione una opcion: ");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
            for(i=0;i<10;i++)
            {
                A[i] = rand() %100;
                neg = rand() %100;
                if(neg%2==0)
                    A[i]*=-1;
            }
        break;
        case 2:
            for(i=0;i<10;i++)
            {
                B[i] = rand() %100;
                neg = rand() %100;
                if(neg%2==0)
                    B[i]*=-1;
            }
        break;
        case 3:
            for(i=0;i<10;i++)
                C[i]=A[i]+B[i];
        break;
        case 4:
            for(i=0;i<10;i++)
                C[i]=B[i]-A[i];
        break;
        case 5:
            printf("Que vector deseas mostrar? (A,B,C): ");
            fflush(stdin);
            scanf("%c",&vector);
            if(vector=='a')
                vector='A';
            if(vector=='b')
                vector='B';
            if(vector=='c')
                vector='C';
            while(vector!='A'&&vector!='B'&&vector!='C')
            {
                printf("Introduzca un vector valido: ");
                fflush(stdin);
                scanf("%c",&vector);
            }
            switch (vector)
            {
            case 'A':
                for(i=0;i<10;i++)
                    printf("%d ",A[i]);
                printf("\n\n");
                system("PAUSE");
            break;
            case 'B':
                for(i=0;i<10;i++)
                    printf("%d ",B[i]);
                printf("\n\n");
                system("PAUSE");
            break;
            case 'C':
                for(i=0;i<10;i++)
                    printf("%d ",C[i]);
                printf("\n\n");
                system("PAUSE");
            break;
            }
        break;
        }
    }while(opc!=6);
    return 0;
}
