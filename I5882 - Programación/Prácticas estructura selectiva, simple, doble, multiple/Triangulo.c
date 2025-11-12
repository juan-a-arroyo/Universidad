#include <stdio.h>
int main(){
    int a,b,c;
    printf("Digite lados de un triangulo:\n");
    scanf("%d %d %d",&a,&b,&c);
    if((a+b)>c && (a+c)>b && (b+c)>a)
    {
        if(a==b || a==c || b==c)
        {
            if(a!=b || a!=c || b!=c)
            {
                printf("Es un triangulo Isoceles");
            }
            else
            printf("Es un triangulo Equilatero");
        }
        else
            printf("Es un triangulo Escaleno");
    }
    else
        printf("No es un triangulo");
return 0;
}
