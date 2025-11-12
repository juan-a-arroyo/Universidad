#include <iostream>
using namespace std;

int calcularMod(string, int, bool);

int main (void)
{
    int ctd, i, espacio, len, opc, cont;
    string elemento;
    char sn;
    bool show=false, found=false;
    cout<<"TABLA DE DISPERSION"<<endl<<endl;
    cout<<"Ingrese el tama"<<char(164)<<"o de la tabla: ";
    cin>>ctd;
    cout<<"Desea ver todos los calculos? Si(s) No(n): ";
    fflush(stdin);
    cin>>sn;
    if(sn=='s'||sn=='S')
        show=true;
    system("CLS");
    string tabla[ctd];
    for(i=0;i<ctd;i++)
    {
        cout<<"Ingresa el elemento numero "<<i+1<<": ";
        fflush(stdin);
        getline(cin, elemento);
        espacio=calcularMod(elemento, ctd, show);
        while(tabla[espacio]!="")
        {
            espacio++;
            if(espacio==ctd)
                espacio=0;
        }
        tabla[espacio]=elemento;
    }
    system("CLS");
    do{
        system("CLS");
        cout<<"TABLA DE DISPERSION"<<endl<<endl;
        cout<<"1. Mostrar Tabla"<<endl<<"2. Buscar Elemento"<<endl<<"3. Salir"<<endl<<endl<<"Seleccion: ";
        cin>>opc;
        system("CLS");
        switch(opc)
        {
        case 1:
        cout<<"TABLA"<<endl;
        for(i=0;i<ctd;i++)
            cout<<i<<". "<<tabla[i]<<endl;
        break;
        case 2:
            cout<<"Ingresa el elemento a buscar: ";
            fflush(stdin);
            getline(cin, elemento);
            espacio=calcularMod(elemento, ctd, false);
            cont=0;
            if(tabla[espacio]==elemento)
            {
                found=true;
            }
            else
            {
                i=espacio+1;
                while(i!=espacio)
                {
                    i++;
                    if(i==ctd)
                        i=0;
                    if(tabla[i]==elemento)
                    {
                        found=true;
                    }
                }
            }
            cout<<"El elemento: "<<elemento;
            if(found==true)
                cout<<" esta en el espacio "<<espacio;
            else
                cout<<" no ha sido encontrado en la tabla";
        break;
        }
        cout<<endl<<endl;
        system("PAUSE");
    }while(opc!=3);
}

int calcularMod(string elemento,int mod, bool show)
{
    int i=0, val=0;
    do{
        val+=int(elemento[i]);
        if(show==true)
            cout<<endl<<"Valor de la "<<elemento[i]<<": "<<int(elemento[i])<<endl<<endl;
        i++;
    }while(elemento[i]!='\0');
    if(show==true)
        cout<<"SUMA: "<<val<<endl<<endl<<"Mod: "<<val%mod<<endl<<endl;
    return val%mod;
}