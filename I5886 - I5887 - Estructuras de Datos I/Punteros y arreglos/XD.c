#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    printf("Ingresa el valor del numero: ");
    scanf("%d",&num);
    int *ptrnum=&num;
    ptrnum=2*num;
    printf("%d\n",ptrnum);
    int array[3];
    *ptrnum=array[3];
    system("PAUSE");
}