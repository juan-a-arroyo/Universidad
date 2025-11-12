/*
Juan Antonio Arroyo Santana - INNI
Práctica 2
Realice un programa que indique si un carácter pedido al usuario es una letra mayúscula,
letra minúscula, número, operador relacional, operador aritmético u otro(símbolo).
*/
#include <stdio.h>
int main () {
    char c;
    printf("Escribe un caracter: ");
    scanf("%c",&c);
    if(c >= 'A' && c <= 'Z')
        printf("Es una letra mayuscula ");
    if(c >= 97 && c <= 122)
        printf("Es una letra minuscula ");
    if (c >= 48 && c <= '9')
        printf("Es un numero ");
    if (c == 60 || c == 61 || c == 62)
        printf("es un operador relacional");
    if( c == 42 || c == 43 || c == 47 || c == 45)
        printf("Es un operador aritmetico ");
    if (!(c >= 'A' && c <= 'Z' || c >= 97 && c <= 122 || c >= 48 && c <= '9' || c == 60 || c == 61 || c == 62 || c == 42 || c == 43 || c == 47 || c == 45))
        printf ("Es un simbolo");
    return 0;
}
