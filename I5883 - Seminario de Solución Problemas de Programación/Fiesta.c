#include <stdio.h>
#include <stdlib.h>
int main (){
    int EDAD,SEXO=0,JOVEN=150,MUJERES=0,HOMBRES=0,PERSONAS=0,PROMEDIO_M=0,PROMEDIO_H=0;
    while(SEXO!=3)
    {
        printf("FIESTA\n\n");
        printf("Introduzca la edad del asistente: ");
        scanf("%d",&EDAD);
        if(EDAD>0&&EDAD<18)
            printf("\nLA ENTRADA ESTA PROHIBIDA A MENORES DE EDAD");
        while(EDAD<18||EDAD>120)
        {
            printf("\n\nIntroduzca una edad valida: ");
            scanf("%d",&EDAD);
            if(EDAD>0&&EDAD<18);
                printf("\nLA ENTRADA ESTA PROHIBIDA A MENORES DE EDAD");
        }
        if(EDAD<JOVEN)
            JOVEN=EDAD;
        printf("\nSexo\n\n1.Mujer\n2.Hombre\n3.Finalizar\n\nIntroduzca una opcion: ");
        scanf("%d",&SEXO);
        while(SEXO<1||SEXO>3)
        {
            printf("Introduzca una opcion valida: ");
            scanf("%d",&SEXO);
        }
        switch(SEXO)
        {
            case 1:
                MUJERES++;
                PERSONAS++;
                PROMEDIO_M+=EDAD;
            break;
            case 2:
                HOMBRES++;
                PERSONAS++;
                PROMEDIO_H+=EDAD;
            break;
        }
        system("cls");
    }
    printf("FIESTA\n\n");
    printf("El total de personas que asistio a la fiesta fue de %d\n",PERSONAS);
    printf("El total de Mujeres que asistio a la fiesta fue de %d\n",MUJERES);
    printf("El total de Hombres que asistio a la fiesta fue de %d\n",HOMBRES);
    printf("El promedio de edad de las Mujeres que asistieron a la fiesta fue de %d\n",PROMEDIO_M/MUJERES);
    printf("El promedio de edad de los Hombres que asistieron a la fiesta fue de %d\n",PROMEDIO_H/HOMBRES);
    printf("La persona mas joven que asistio a la fiesta fue de %d\n",JOVEN);
    return 0;
}
