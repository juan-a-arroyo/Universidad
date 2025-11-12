//Juan Antonio Arroyo Santana - INNI
//Práctica 2
//Realice un programa que solicite al usuario su edad y le diga cuantos días han transcurrido desde su nacimiento.
//(considere años completos y no tome en cuenta los años bisiestos).
#include <stdio.h>
int main ()
{
    int EDAD;
    printf("Inserte su edad: ");
    scanf ("%u",&EDAD);
    printf ("%u", EDAD*365);
    return 0;
}
