#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void write(char const *NombreArchivo, char const *Nombre, char const *RFC, char const *Direccion,
char const *Ciudad, char const *Estado, char const *Codigo, char const *Lesion, char const *Fisio)
{
    FILE* archivo = fopen(NombreArchivo,"a");
    if(!archivo)
    {
        printf("Error al crear archivo");
        return;
    }
    fputs(Nombre, archivo);
    fputs("|", archivo);
    fputs(RFC, archivo);
    fputs("|", archivo);
    fputs(Direccion, archivo);
    fputs("|", archivo);
    fputs(Ciudad, archivo);
    fputs("|", archivo);
    fputs(Estado, archivo);
    fputs("|", archivo);
    fputs(Codigo, archivo);
    fputs("|", archivo);
    fputs(Lesion, archivo);
    fputs("|", archivo);
    fputs(Fisio, archivo);
    fputs("\n", archivo);
    fclose(archivo);
}

void read(const char *NombreArchivo)
{
    int i;
    char caracter;
    char nombre[30]; //Nombre del cliente,
    char rfc[30]; //RFC para facturacion,
    char direccion[30];//Direccion,
    char ciudad[30];//Ciudad,
    char estado[30];//Estado,
    char codigo[6];//Codigo postal y
    char lesion[100];//Lesion diagnosticada
    char fisio[30];//Fisioterapeuta asignado.
    FILE* archivo = fopen(NombreArchivo,"r");
    if(archivo==NULL)
    {
        printf("Error al abrir el archivo");
        return;
    }
    //if(fgets(nombre,30,archivo))
    //    printf("%s", nombre);
    caracter=fgetc(archivo);
    do{
        for(i=0;i<30;i++)
        {
            nombre[i]='\0';
            rfc[i]='\0';
            direccion[i]='\0';
            ciudad[i]='\0';
            estado[i]='\0';
            fisio[i]='\0';
        }
        for(i=0;i<6;i++)
            codigo[i]='\0';
        for(i=0;i<100;i++)
            lesion[i]='\0';
            i=0;
        do{
            if(i>0)
                caracter=fgetc(archivo);
            if(caracter!='|')
                nombre[i]=caracter;
            printf("%c",caracter);
            i++;
        }while(!feof(archivo)&&caracter!='|');
        i=0;
        do{
            caracter=fgetc(archivo);
            if(caracter!='|')
                rfc[i]=caracter;
            printf("%c",caracter);
            i++;
        }while(!feof(archivo)&&caracter!='|');
        i=0;
        do{
            caracter=fgetc(archivo);
            if(caracter!='|')
                direccion[i]=caracter;
            printf("%c",caracter);
            i++;
        }while(!feof(archivo)&&caracter!='|');
        i=0;
        do{
            caracter=fgetc(archivo);
            if(caracter!='|')
                ciudad[i]=caracter;
            printf("%c",caracter);
            i++;
        }while(!feof(archivo)&&caracter!='|');
        i=0;
        do{
            caracter=fgetc(archivo);
            if(caracter!='|')
                estado[i]=caracter;
            printf("%c",caracter);
            i++;
        }while(!feof(archivo)&&caracter!='|');
        i=0;
        do{
            caracter=fgetc(archivo);
            if(caracter!='|')
                codigo[i]=caracter;
            printf("%c",caracter);
            i++;
        }while(!feof(archivo)&&caracter!='|');
        i=0;
        do{
            caracter=fgetc(archivo);
            if(caracter!='|')
                lesion[i]=caracter;
            printf("%c",caracter);
            i++;
        }while(!feof(archivo)&&caracter!='|');
        i=0;
        do{
            caracter=fgetc(archivo);
            if(caracter!='\n')
                fisio[i]=caracter;
            printf("%c",caracter);
            i++;
        }while(!feof(archivo)&&caracter!='\n');
        caracter=fgetc(archivo);
        printf("%s\n",nombre);
        printf("%s\n",rfc);
        printf("%s\n",direccion);
        printf("%s\n",ciudad);
        printf("%s\n",estado);
        printf("%s\n",codigo);
        printf("%s\n",lesion);
        printf("%s\n",fisio);
    }while(!feof(archivo));
    fclose(archivo);
}

int main()
{
    char Nombre[30]; //Nombre del cliente,
    char RFC[30]; //RFC para facturacion,
    char Direccion[30];//Direccion,
    char Ciudad[30];//Ciudad,
    char Estado[30];//Estado,
    char Codigo[6];//Codigo postal y
    char Lesion[100];//Lesion diagnosticada
    char Fisio[30];//Fisioterapeuta asignado.
    char NombreArchivo[30];

    /*printf("Nombre del cliente: ");
    fflush(stdin);
    gets(Nombre);
    printf("RFC: ");
    fflush(stdin);
    gets(RFC);
    printf("Direccion: ");
    fflush(stdin);
    gets(Direccion);
    printf("Ciudad: ");
    fflush(stdin);
    gets(Ciudad);
    printf("Estado: ");
    fflush(stdin);
    gets(Estado);
    printf("Codigo Postal: ");
    gets(Codigo);
    printf("Lesion Diagnosticada: ");
    fflush(stdin);
    gets(Lesion);
    printf("Fisioterapeuta Asignado: ");
    fflush(stdin);
    gets(Fisio);
    printf("Nombre del archivo: ");
    fflush(stdin);*/
    gets(NombreArchivo);
    read(NombreArchivo);
    //write(NombreArchivo, Nombre, RFC, Direccion, Ciudad, Estado, Codigo, Lesion, Fisio);
    system("PAUSE");
    return 0;
}


