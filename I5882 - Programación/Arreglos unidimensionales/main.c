#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,i,opc,cuad,may=-2147483648,may_cout=0,min=2147483647,min_cout=0,par_cout=0,impar_cout=0;
    printf("Inserte el tama%co del arreglo que desea: ",164);
    scanf("%d",&n);
    printf("\n\n");

    int num[n];
    for(i=0;i<=n-1;i++)
    {
        printf ("Inserte el valor %d: ",i+1);
        scanf("%d",&num[i]);
        if(num[i]%2==0)
            par_cout++;
        else
            impar_cout++;
    }
    printf("\n\n1.Cuadrados\n2.Numero Mayor\n3.Numero Menor\n4.Numeros Pares\n5.Numeros impares\n\nSeleccione una opcion: ");
    scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        for(i=0;i<=n-1;i++)
        {
            cuad=pow(num[i],2);
            printf("%d  ",cuad);
        }
    break;
    case 2:
        for(i=0;i<=n-1;i++)
        {
            if(num[i]>may)
                may=num[i];
        }
        printf("El numero mayor es: %d",may);
        for(i=0;i<=n-1;i++)
        {
            if(num[i]==may)
                may_cout++;
        }
        printf("\n\nEl numero mayor se repite %d veces",may_cout);
    break;
    case 3:
        for(i=0;i<=n-1;i++)
        {
            if(num[i]<min)
                min=num[i];
        }
        printf("El numero menor es: %d",min);
        for(i=0;i<=n-1;i++)
        {
            if(num[i]==min)
                may_cout++;
        }
        printf("\n\nEl numero menor se repite %d veces",min_cout);
    break;
    /*case 4:
        int par[par_cout];
        for(i=0;i<=n-1;i++)
        {
            if(num[i]%2==0)
            par[i]=
        }
    break;*/
    }
    /*for(i=0;i<=n-1;i++)
    {
        printf("%d - ",num[i]);
    }*/
    return 0;
}
