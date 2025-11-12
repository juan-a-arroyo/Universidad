#include <stdio.h>
int main(){
    int ANIOS,SUELDO;
    printf("Introduzca anios en la empresa: ");
    scanf("%d",&ANIOS);
    printf("Introduzca Sueldo: $");
    scanf("%d",&SUELDO);
    if(ANIOS>10)
        SUELDO=SUELDO*1.10;
    else
    {
        if(ANIOS>5)
            SUELDO=SUELDO*1.07;
        else
        {
            if(ANIOS>3)
                SUELDO=SUELDO*1.05;
            else
                SUELDO=SUELDO*1.03;
        }
    }
    printf("Su nuevo sueldo es: %d",SUELDO);
    return 0;
}
