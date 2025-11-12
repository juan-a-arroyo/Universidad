#include <stdio.h>
#include <math.h>
int frecuencia(int nu, int n);

int main ()
{
    int nums, num;
    printf("Ingrese un numero: ");
    scanf("%d",&nums);
    printf("Ingrese el numero a contar: ");
    scanf("%d",&num);
    frecuencia(num, nums);
    printf("\nEl total de repeticiones del numero %d es: %d\n",num,frecuencia(num,nums));
    return 0;
}

int frecuencia(int nu, int n)
{
    int res, i=0, val, nums=0, band=0, lon;
    int numeros[10]={};

    do
    {
        i++;
        val=pow(10,i);
        res=n%10;
        n=(n-res)/10;
        numeros[i]=res;
    }while(res!=0);
    for(i=9;i>0;i--)
    {
        if(numeros[i]>0)
            band=1;
        if(band==1)
            if(numeros[i]==nu)
                nums++;

    }
    return nums;
}
