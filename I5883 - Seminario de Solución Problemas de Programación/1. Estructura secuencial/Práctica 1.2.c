//Juan Antonio Arroyo Santana - INNI
//Práctica 2
//Realice un programa que  muestre en pantalla el tamaño en bytes de cada tipo de dato así como su rango de valores. (int, float, long, char)
#include <stdio.h>
#include <limits.h>
#include <float.h>
int main ()
{
    printf("El tamano en Bytes de int es: %lu\n", sizeof(int));
    printf("El tamano en Bits de int es: %lu\n", sizeof(int)*8);
    printf("El minimo del rango de int es: %i\n", INT_MIN);
    printf("El maximo del rango de int es: %i\n", INT_MAX);
    printf("\n");
    printf("El tamano en Bytes de float es: %lu\n", sizeof(float));
    printf("El tamano en Bits de float es: %lu\n", sizeof(float)*8);
    printf("El minimo del rango de float es: %e\n", FLT_MIN);
    printf("El maximo del rango de float es: %e\n", FLT_MAX);
    printf("\n");
    printf("El tamano en Bytes de long es: %lu\n", sizeof(long));
    printf("El tamano en Bits de long es: %lu\n", sizeof(long)*8);
    printf("El minimo del rango de long es: %ld\n", LONG_MIN);
    printf("El maximo del rango de long es: %ld\n", LONG_MAX);
    printf("\n");
    printf("El tamano en Bytes de char es: %lu\n", sizeof(char));
    printf("El tamano en Bits de char es: %lu\n", sizeof(char)*8);
    printf("El minimo del rango de char es: %i\n", CHAR_MIN);
    printf("El maximo del rango de char es: %i\n", CHAR_MAX);
    return 0;
}
