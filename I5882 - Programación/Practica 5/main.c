#include <stdio.h>
int main()
{
    int NUMERO;
    printf("Digite un numero de 5 cifras: ");
    scanf("%d",&NUMERO);
    if (NUMERO>9999&&NUMERO<100000)
    {
        printf("%d",NUMERO%10);
        NUMERO/=10;
        printf("%d",NUMERO%10);
        NUMERO/=10;
        printf("%d",NUMERO%10);
        NUMERO/=10;
        printf("%d",NUMERO%10);
        NUMERO/=10;
        printf("%d",NUMERO%10);
        NUMERO/=10;
    }
    else
        printf("Numero invalido");
    return 0;
}
