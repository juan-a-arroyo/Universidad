#include <stdio.h>
#include <stdlib.h>
struct libro
{
    int codigo1, anio1;
    char autor[30], titulo1[30], editorial[30];
}lib;
struct revista
{
    int codigo2, mes, anio2;
    char nombre[30];
}rev;
struct pelicula
{
    int codigo3, anio3;
    char director[30], titulo3[30], productora[30];
}pel;
union tabla
{
    struct libro lib;
    struct revista rev;
    struct pelicula pel;
};

union tabla tab[100];

int main(void)
{
    int  menu, type[100]={}, x=-1;
    union tabla tab[100];
    do{
        x++;
        system("cls");
        printf("ELEMENTO %d\nIngrese el tipo de informaci%cn: \n 1.Libro\n 2.Revista\n 3.Pelicula\n 4.Mostrar Tabla\nSelecc%cn: ",x+1,162,162);
        scanf("%d",&menu);
        system("cls");
        switch (menu)
        {
        case 1:
            printf("Escribe el Codigo del libro: ");
            scanf("%d",&tab[x].lib.codigo1);
            printf("Escribe el Autor del libro: ");
            fflush(stdin);
            gets(tab[x].lib.autor);
            printf("Escribe el Titulo del libro: ");
            fflush(stdin);
            gets(tab[x].lib.titulo1);
            printf("Escribe la Editorial del libro: ");
            fflush(stdin);
            gets(tab[x].lib.editorial);
            printf("Escribe el A%co del libro: ",164);
            scanf("%d",&tab[x].lib.anio1);
            type[x]=menu;
            break;
        case 2:
            printf("Escribe el Codigo de la revista: ");
            scanf("%d",&tab[x].rev.codigo2);
            printf("Escribe el Nombre de la revista: ");
            fflush(stdin);
            gets(tab[x].rev.nombre);
            printf("Escribe el Mes de la revista: ");
            scanf("%d",&tab[x].rev.mes);
            printf("Escribe el A%co de la revista: ",164);
            scanf("%d",&tab[x].rev.anio2);
            type[x]=menu;
            break;
        case 3:
            printf("Escribe el Codigo de la Pelicula: ");
            scanf("%d",&tab[x].pel.codigo3);
            printf("Escribe el Director de la Pelicula: ");
            fflush(stdin);
            gets(tab[x].pel.director);
            printf("Escribe el Titulo de la Pelicula: ");
            fflush(stdin);
            gets(tab[x].pel.titulo3);
            printf("Escribe la Productora de la Pelicula: ");
            fflush(stdin);
            gets(tab[x].pel.productora);
            printf("Escribe el A%co de la Pelicula: ",164);
            scanf("%d",&tab[x].pel.anio3);
            type[x]=menu;
            break;
        }
    }while(menu<4&&x<=100);
    printf("TABLA\n");
    for(x=0;x<100;x++)
    {
        if(type[x]==1)
            printf("\n%d.\nEl codigo es: %d\nEl Autor es: %s\nEl titulo es: %s\nla editorial es: %s\nEl a%co es: %d\n",x+1,tab[x].lib.codigo1,tab[x].lib.autor,tab[x].lib.titulo1,tab[x].lib.editorial,164,tab[x].lib.anio1);
        if(type[x]==2)
            printf("\n%d.\nEl codigo es: %d\nEl Nombre es: %s\nEl Mes es: %d\nEl a%co es: %d\n",x+1,tab[x].rev.codigo2,tab[x].rev.nombre,tab[x].rev.mes,164,tab[x].rev.anio2);
        if(type[x]==3)
            printf("\n%d.\nEl codigo es: %d\nEl Director es: %s\nEl titulo es: %s\nLa productora es: %s\nEl a%co es: %d\n",x+1,tab[x].pel.codigo3,tab[x].pel.director,tab[x].pel.titulo3,tab[x].pel.productora,164,tab[x].pel.anio3);
    }
    system("PAUSE");
    return 0;
}