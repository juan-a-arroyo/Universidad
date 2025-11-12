#include <iostream>
#include <stdlib.h>
using namespace std;

int hashing(string);

int main (void)
{
    string names[11];
    string name;
    int key, option, count;
    bool k;
    do{
        cout<<"MENU"<<endl
        <<"1. Insertar"<<endl
        <<"2. Buscar"<<endl
        <<"3. Salir"<<endl<<endl
        <<"Opcion: ";
        cin>>option;
        switch (option)
        {
        case 1:
            for(int i = 0;i<11;i++)
            {
                cout<<"Inserte un nombre: ";
                fflush(stdin);
                getline(cin, name);
                key = hashing(name);
                k=false;
                while(k==false)
                    if(names[key]== "")
                    {
                        names[key]=name;
                        k=true;
                    }
                    else
                    {
                        key++;
                        key%=11;
                    }
            }
        break;
        case 2:
            cout<<"Inserte un nombre: ";
            fflush(stdin);
            getline(cin, name);
            key = hashing(name);
            k=false;
            count=0;
            while(k==false&&count<11)
            {
                if(names[key]==name)
                {
                    cout<<endl<<name<<" Esta en la posicion: "<<key<<endl;
                    k=true;
                }
                else
                {
                    key++;
                    key%=11;
                }
                count++;
            }
            if(k==false)
                cout<<endl<<name<<" No esta en ninguna posicion de la tabla"<<endl;
            system("PAUSE");
        break;
        }
        system("CLS");
    }while(option>0&&option<3);
    for(int i = 0;i<11;i++)
        cout<<i<<". "<<names[i]<<endl;
    system("PAUSE");
}

int hashing(string name)
{
    int i, len, key=0;
    len = name.length();
    for(i = 0; i<len; i++)
    {
        //key+=(name[i]*len)%11;
        key+=name[i];
    }
    key%=11;
    return key;
}