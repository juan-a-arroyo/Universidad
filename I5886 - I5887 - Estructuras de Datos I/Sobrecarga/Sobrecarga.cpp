#include <iostream>
#include <cstdlib>
using namespace std;
class Alumno
{
    private:
        string nombre;
        int matematicas;
        int fisica;
        int quimica;
    public:
        void Alumno_ ();
        void Alumno_ (string &name,int mate,int fis,int qui);
        void setName(string &name);
        void setMate(int mate);
        void setFis(int fis);
        void setQui(int qui);
        friend ostream& operator<<(ostream &out, const Alumno &a)
        {
            out<<a.nombre<<"\t\t";
            out<<(a.matematicas+a.fisica+a.quimica)/3;
            return out; 
        }
};

void Alumno::Alumno_ (){}
void Alumno::Alumno_ (string &name,int mate,int fis,int qui)
{
    this->nombre = name;
    this->matematicas = mate;
    this->fisica = fis;
    this->quimica = qui;
}

void Alumno::setName(string &name)
{
    nombre = name;
}

void Alumno::setMate(int mate)
{
    matematicas = mate;
}

void Alumno::setFis(int fis)
{
    fisica = fis;
}

void Alumno::setQui(int qui)
{
    quimica = qui;
}

int main (void)
{
    string name;
    int i, opc, ctd, mod, dato, mate, fis, qui;
    cout<<"Ingrese cuantos estudiantes hay: ";
    cin>>ctd;
    system("CLS");
    Alumno alumnos[ctd];
    do{
        system("CLS");
        cout<<"MENU"<<endl<<endl;
        cout<<"1. Capturar datos"<<endl<<"2. Modificar un Dato"<<endl<<"3. Mostrar Alumnos"<<endl<<"4. Salir"<<endl<<endl<<"Ingrese una opcion: ";
        cin>>opc;
        switch(opc)
        {
            case 1:
            for(i=0;i<ctd;i++)
            {
                system("CLS");
                cout<<"CAPTURAR DATOS"<<endl<<endl;
                cout<<"Ingrese el nombre del Alumno "<<i+1<<": ";
                cin>>name;
                cout<<"Ingrese la calificacion de matematicas: ";
                do{
                    cin>>mate;
                    if(mate<50||mate>100)
                        cout<<"Ingrese una calificacion valida (50-100): ";
                }while(mate<50||mate>100);
                cout<<"Ingrese la calificacion de fisica: ";
                do{
                    cin>>fis;
                    if(fis<50||fis>100)
                        cout<<"Ingrese una calificacion valida (50-100): ";
                }while(fis<50||fis>100);
                cout<<"Ingrese la calificacion de quimica: ";
                do{
                    cin>>qui;
                    if(qui<50||qui>100)
                        cout<<"Ingrese una calificacion valida (50-100): ";
                }while(qui<50||qui>100);
                system("CLS");
                alumnos[i].Alumno_(name,mate,fis,qui);
            }
        break;
        case 2:
            system("CLS");
            cout<<"MODIFICAR UN DATO"<<endl<<endl;
            cout<<"Que numero de alumno desea modificar: ";
            cin>>mod;
            mod--;
            cout<<endl<<"Que dato desea modificar: "<<endl<<endl<<"1. Nombre"<<endl<<"2. Calificacion de Matematicas"<<endl<<"3. Calificacion de Fisica"<<endl<<"4. Calificacion de Quimica"<<endl<<"5. Cancelar"<<endl<<endl<<"Ingrese una opcion: ";
            cin>>dato;
            switch(dato)
            {
                case 1:
                    cout<<"Ingrese el nuevo nombre: ";
                    cin>>name;
                    alumnos[mod].setName(name);
                break;
                case 2:
                    cout<<"Ingrese la nueva calificacion de matematicas: ";
                    cin>>mate;
                    alumnos[i].setMate(mate);
                break;
                case 3:
                    cout<<"Ingrese la nueva calificacion de fisica: ";
                    cin>>fis;
                    alumnos[i].setFis(fis);
                break;
                case 4:
                    cout<<"Ingrese la nueva calificacion de quimica: ";
                    cin>>qui;
                    alumnos[i].setQui(qui);
                break;
            }
        break;
        case 3:
            system("CLS");
            cout<<"MOSTRAR ALUMNOS"<<endl<<endl;
            for(i=0;i<ctd;i++)
                cout<<"Alumno "<<i+1<<": "<<alumnos[i]<<endl;
            system("PAUSE");
        break;
        }
    }while(opc!=4);
    return 0;
}