#include <stdio.h>
#include <stdlib.h>
int conteo();

int main(){
    char cadena[100]={};
    printf("Escriba una Frase: ");
    gets(cadena);
    conteo(cadena);
    printf("\nLa longitud de la ultima palabra es: %d\n",conteo(cadena));
    return 0;
}

int conteo(char character[100])
{
    int i, longitud=0;
    for(i=99;i>0;i--)
    {
        if(character[i]==' ')
            break;
        if(character[i]!='\0')
            longitud++;
    }
    return longitud;
}
