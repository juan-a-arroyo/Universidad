#include <stdio.h>
int main (){
    int DIA,MES,ANIO,DIA_N,MES_N,ANIO_N,DIAS,MESES,ANIOS;
    printf("Introduzca fecha Actual (dd/mm/aaaa): \n");
    scanf("%d %d %d",&DIA,&MES,&ANIO);
    if (DIA>=1&&MES>=1&&(DIA<=31||((MES==4||MES==6||MES==9||MES==11)&&DIA<=30)||(MES==2&&DIA<=28)))
    {
        printf("Introduzca fecha de nacimiento (dd/mm/aaaa): \n");
        scanf("%d %d %d",&DIA_N,&MES_N,&ANIO_N);
        if (DIA_N>=1&&MES_N>=1&&(DIA_N<=31||((MES_N==4||MES_N==6||MES_N==9||MES_N==11)&&DIA_N<=30)||(MES_N==2&&DIA_N<=28)))
        {
            if(ANIO>ANIO_N||ANIO==ANIO_N&&MES==MES_N&&DIA>=DIA_N||ANIO==ANIO_N&&MES>MES_N)
            {
                ANIOS=ANIO-ANIO_N;
				MESES=MES-MES_N;
				DIAS=DIA-DIA_N;
				if(MESES<0)
                {
                    ANIOS=ANIOS-1;
                    MESES=12+(MESES);
                }
                if(DIAS<0)
                {
                    MESES=MESES-1;
                    switch (MESES)
                    {
                        case 1:
                            DIAS=DIAS+31;
                        break;
                        case 2:
                            DIAS=DIAS+28;
                        break;
                        case 3:
                            DIAS=DIAS+31;
                        break;
                        case 4:
                            DIAS=DIAS+30;
                        break;
                        case 5:
                            DIAS=DIAS+31;
                        break;
                        case 6:
                            DIAS=DIAS+30;
                        break;
                        case 7:
                            DIAS=DIAS+31;
                        break;
                        case 8:
                            DIAS=DIAS+31;
                        break;
                        case 9:
                            DIAS=DIAS+30;
                        break;
                        case 10:
                            DIAS=DIAS+31;
                        break;
                        case 11:
                            DIAS=DIAS+30;
                        break;
                        case 12:
                            DIAS=DIAS+31;
                        break;
                    }
                }
                printf("Usted tiene %d a%cos, %d meses y %d d%cas",ANIOS,164,MESES,DIAS,161);
            }
            else
                printf("A%cn no has nacido",163);
        }
        else
            printf("Fecha de nacimiento inv%clida",160);
    }
    else
        printf("Fecha actual inv%clida",160);
    return 0;
}
