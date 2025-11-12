/*
Juan Antonio Arroyo Santana - INNI (220792779)
4.- Realice un programa que muestre un menú de opciones, de una tienda departamental o de una tienda de artículos de oficina y papelería con sus diferentes departamentos  (mínimo 4 departamentos) y por cada departamento debe mostrar 5 artículos que ofrece el departamento.
El usuario podrá elegir un artículo y el programa debe mostrar las características y el precio.
el programa se debe repetir mientras que el usuario no elija la opción salir.

NOTA: Puede utilizar los tres ciclos, es a decisión propia.
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int DEPARTAMENTO,PRODUCTO;
    char ENTER;
    do{
        system("cls");
        printf("TIENDA DEPARTAMENTAL\n\n");
        printf("Departamentos: ");
        printf("\n\n1.Ni%cos\n2.Damas\n3.Caballeros\n4.Perfumer%ca\n5.Electr%cnica\n6.Salir\n\nSeleccione un departamento: ",164,161,162);
        scanf("%d",&DEPARTAMENTO);
        while(DEPARTAMENTO<1||DEPARTAMENTO>6)
        {
            printf("Seleccione una opci%cn v%clida",162,160);
            scanf("%d",&DEPARTAMENTO);
        }
        switch(DEPARTAMENTO)
        {
        case 1:
            do{
                system("cls");
                printf("Departamento de Ni%cos\n\n",164);
                printf("1.Chamarra azul\n2.Pantal%cn de mezclilla\n3.Zapatos negros\n4.Tenis deportivos\n5.Su%cter rojo\n6.Atr%cs\n",162,130,160);
                printf("\nSeleccione un producto: ");
                scanf("%d",&PRODUCTO);
                while(PRODUCTO<1||PRODUCTO>6)
                {
                    printf("Seleccione una opci%cn v%clida",162,160);
                    scanf("%d",&PRODUCTO);
                }
                switch (PRODUCTO)
                {
                case 1:
                    system ("cls");
                    printf("Chamarra Azul\n\nPrecio: $950\nChamarra azul con detalles blancos\nTallas disponibles: 6 a%cos a 12 a%cos\n\n",164,164);
                    system("PAUSE");
                break;
                case 2:
                    system ("cls");
                    printf("Pantal%cn de mezclilla\n\nPrecio: $650\nPantal%cn de mezclilla con el%cstico\nTallas disponibles: 6 a%cos a 12 a%cos\n\n",162,162,160,164,164);
                    system("PAUSE");
                break;
                case 3:
                    system ("cls");
                    printf("Zapatos Negros\n\nPrecio: $800\nZapatos negros escolares con velcro\nTallas disponibles: 18cm a 23cm\n\n");
                    system("PAUSE");
                break;
                case 4:
                    system ("cls");
                    printf("Tenis Deportivos\n\nPrecio: $1050\nTenis Deportivos blancos con franjas azules\nTallas disponibles: 18cm a 23cm\n\n");
                    system("PAUSE");
                break;
                case 5:
                    system ("cls");
                    printf("Su%cter Rojo\n\nPrecio: $450\nSu%cter rojo con detalles blancos\nTallas disponibles: 6 a%cos a 12 a%cos\n\n",130,130,164,164);
                    system("PAUSE");
                break;
                }
            }while(PRODUCTO>0&&PRODUCTO<=5);
        break;
        case 2:
            do{
                system("cls");
                printf("Departamento de Damas\n\n");
                printf("1.Blusa blanca\n2.Pantal%cn negro\n3.Tacones dorados\n4.Tenis rosas\n5.Vestido amarillo\n6.Atr%cs\n",162,160);
                printf("\nSeleccione un producto: ");
                scanf("%d",&PRODUCTO);
                while(PRODUCTO<1||PRODUCTO>6)
                {
                    printf("Seleccione una opci%cn v%clida",162,160);
                    scanf("%d",&PRODUCTO);
                }
                switch (PRODUCTO)
                {
                case 1:
                    system ("cls");
                    printf("Blusa Blanca\n\nPrecio: $750\nBlusa blanca con encaje\nTallas disponibles: C, M, G, EG\n\n");
                    system("PAUSE");
                break;
                case 2:
                    system ("cls");
                    printf("Pantal%cn negro\n\nPrecio: $1250\nPantal%cn negro con bolsas al frente\nTallas disponibles: 7 a 15\n\n",162,162);
                    system("PAUSE");
                break;
                case 3:
                    system ("cls");
                    printf("Tacones dorados\n\nPrecio: $1050\nTacones dorados de plataforma brillantes\nTallas disponibles: 22cm a 27cm\n\n");
                    system("PAUSE");
                break;
                case 4:
                    system ("cls");
                    printf("Tenis Rosas\n\nPrecio: $1250\ntenia Rosas con detalles blancos\nTallas disponibles: 22cm a 27cm\n\n");
                    system("PAUSE");
                break;
                case 5:
                    system ("cls");
                    printf("Vestido amarillo\n\nPrecio: $1350\nVestido amarillo en l%cnea A\nTallas disponibles: C, M, G, EG\n\n",161);
                    system("PAUSE");
                break;
                }
            }while(PRODUCTO>0&&PRODUCTO<=5);
        break;
        case 3:
            do{
                system("cls");
                printf("Departamento de Caballeros\n\n");
                printf("1.Camisa azul\n2.Pantal%cn de mezclilla\n3.Chamarra de cuero\n4.Zapatos de vestir negros\n5.Fajo Reversible\n6.Atr%cs\n",162,160);
                printf("\nSeleccione un producto: ");
                scanf("%d",&PRODUCTO);
                while(PRODUCTO<1||PRODUCTO>6)
                {
                    printf("Seleccione una opci%cn v%clida",162,160);
                    scanf("%d",&PRODUCTO);
                }
                switch (PRODUCTO)
                {
                case 1:
                    system ("cls");
                    printf("Camisa Azul\n\nPrecio: $550\nCamisa Azul de botones\nTallas disponibles: C, M, G, EG\n\n");
                    system("PAUSE");
                break;
                case 2:
                    system ("cls");
                    printf("Pantal%cn de Mezclilla\n\nPrecio: $950\nPantal%cn de mezclilla entubado\nTallas disponibles: 28 a 38\n\n",162,162);
                    system("PAUSE");
                break;
                case 3:
                    system ("cls");
                    printf("Chamarra de cuero\n\nPrecio: $1500\nChamarra de cuero con borrega\nTallas disponibles: C, M, G, EG\n\n");
                    system("PAUSE");
                break;
                case 4:
                    system ("cls");
                    printf("Zapatos de vestir negros\n\nPrecio: $1250\nZapatos de vestir negro brillante con cintas\nTallas disponibles: 24cm a 29cm\n\n");
                    system("PAUSE");
                break;
                case 5:
                    system ("cls");
                    printf("Fajo Reversible\n\nPrecio: $250\nFajo reversible, mitad Negro, Mitad caf%c\nTallas disponibles: 28 a 38\n\n",130);
                    system("PAUSE");
                break;
                }
            }while(PRODUCTO>0&&PRODUCTO<=5);
        break;
        case 4:
            do{
                system("cls");
                printf("Departamento de Perfumer%ca\n\n",161);
                printf("1.Perfume Versace\n2.Perfume Carolina Herrera\n3.Perfume Oscar de la Renta\n4.Perfume Carlo Corinto\n5.Perfume Paris Hilton\n6.Atr%cs\n",160);
                printf("\nSeleccione un producto: ");
                scanf("%d",&PRODUCTO);
                while(PRODUCTO<1||PRODUCTO>6)
                {
                    printf("Seleccione una opci%cn v%clida",162,160);
                    scanf("%d",&PRODUCTO);
                }
                switch (PRODUCTO)
                {
                case 1:
                    system ("cls");
                    printf("Perfume Versace\n\nPrecio: $1350\nContenido:120ml\n\n");
                    system("PAUSE");
                break;
                case 2:
                    system ("cls");
                    printf("Perfume Carolina Herrera\n\nPrecio: $2200\nContenido:125ml\n\n");
                    system("PAUSE");
                break;
                case 3:
                    system ("cls");
                    printf("Perfume Oscar de la Renta\n\nPrecio: $1000\nContenido:30ml\n\n");
                    system("PAUSE");
                break;
                case 4:
                    system ("cls");
                    printf("Perfume Carlo Corinto\n\nPrecio: $1350\nContenido:55ml\n\n");
                    system("PAUSE");
                break;
                case 5:
                    system ("cls");
                    printf("Perfume Paris Hilton\n\nPrecio: $1300\nContenido:100ml\n\n");
                    system("PAUSE");
                break;
                }
            }while(PRODUCTO>0&&PRODUCTO<=5);
        break;
        case 5:
            do{
                system("cls");
                printf("Departamento de Electr%cnica\n\n",162);
                printf("1.Samsung Galaxy Note20 Ultra\n2.iPhone 12 Pro Max\n3.Aud%cfonos Sony\n4.Pantalla LG Smart TV 65%c\n5.Licuadora Oster\n6.Atr%cs\n",161,34,160);
                printf("\nSeleccione un producto: ");
                scanf("%d",&PRODUCTO);
                while(PRODUCTO<1||PRODUCTO>6)
                {
                    printf("Seleccione una opci%cn v%clida",162,160);
                    scanf("%d",&PRODUCTO);
                }
                switch (PRODUCTO)
                {
                case 1:
                    system ("cls");
                    printf("Samsung Galaxy Note20 Ultra\n\nPrecio: $32000\nProcesador: Samsung Exynos 990\nC%cmara: 108Mpx\nAlmacenamiento: 256GB\nRAM: 12GB\n\n",160);
                    system("PAUSE");
                break;
                case 2:
                    system ("cls");
                    printf("iPhone 12 pro Max\n\nPrecio: $40000\nProcesador: Apple A14 Bionic\nC%cmara: 12Mpx\nAlmacenamiento: 128GB\nRAM: 4GB\n\n",160);
                    system("PAUSE");
                break;
                case 3:
                    system ("cls");
                    printf("Audífonos Sony\n\nPrecio: $1250\nTipo: Supraurales\nSensibilidad 102db/W\nInal%cmbricos: S%c\n\n",160,161);
                    system("PAUSE");
                break;
                case 4:
                    system ("cls");
                    printf("Pantalla LG Smart TV 65%c\n\nPrecio: $15800\nTipo: OLED\n\n\n",34);
                    system("PAUSE");
                break;
                case 5:
                    system("cls");
                    printf("Licuadora Oster\n\nPrecio: $1500\nPotencia: 600W\nTama%co de la jarra: 5 Tazas\nVelocidades: 5\n\n",164);
                    system("PAUSE");
                break;
                }
            }while(PRODUCTO>0&&PRODUCTO<=5);
        break;
        }
    }while(DEPARTAMENTO>0&&DEPARTAMENTO<=5);
    return 0;
}
