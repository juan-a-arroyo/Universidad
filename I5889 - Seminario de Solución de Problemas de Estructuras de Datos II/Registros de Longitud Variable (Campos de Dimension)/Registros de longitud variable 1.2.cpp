#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Producto{
    private:
        string nombre;
        float costo;
        float precio;
        string codigo;
        int existencias;
    public:
        Producto *next;
        Producto(){
            nombre = "";
            costo = 0.0;
            precio = 0.0;
            codigo ="";
            }
        Producto(string _nombre, float _costo, float _precio, string _codigo, int _existencias){
            nombre = _nombre;
            costo = _costo;
            precio = _precio;
            codigo = _codigo;
            existencias = _existencias;
        }
        string getNombre(){return nombre;}
        void setNombre(string _nombre){nombre = _nombre;}
        float getCosto(){return costo;}
        void setCosto(float _costo){costo = _costo;}
        float getPrecio(){return precio;}
        void setPrecio(float _precio){precio = _precio;}
        string getCodigo(){return codigo;}
        void setCodigo(string _codigo){codigo = _codigo;}
        int getExixtencias(){return existencias;}
        void setExistencias(int _existencias){existencias = _existencias;}
};

class Lista{
    private:
    Producto *head, *tail;
    public:
        Lista(){head = tail = nullptr;}
        void agregar(string, float, float, string, int);
        void buscar(string);
        void modificar();
        void eliminar();
        void escribir(string);
        void leer();
        friend ostream& operator << (ostream &out, const Lista &lista){
            if(lista.head == nullptr)
                out<<"[LISTA VACIA]"<<endl<<endl;
            Producto *producto;
            producto = lista.head;
            int posicion = 1;
            while(producto != nullptr){
                out<<posicion<<endl<<"Nombre: "<<producto->getNombre()<<endl<<
                "Costo: "<<producto->getCosto()<<endl<<
                "Precio: "<<producto->getPrecio()<<endl<<
                "Codigo: "<<producto->getCodigo()<<endl<<
                "Existencias: "<<producto->getExixtencias()<<endl<<endl;
                posicion++;
                producto = producto -> next;
            }
            return out;
        }
};

int main (void){
    Lista productos;
    string nombre, codigo, busqueda, nombreArchivo;
    float costo, precio;
    int existencias, opcion;
    cout<<"ARCHIVO"<<endl<<endl<<"Nombre del Archivo a trabajar (sin extension): ";
    fflush(stdin);
    getline(cin, nombreArchivo);
    nombreArchivo+=".txt";
    do{
        system("CLS");
        cout<<"REGISTROS DE LONGITUD VARIABLE"<<endl<<endl<<
        "Productos"<<endl<<
        "1. Agregar"<<endl<<
        "2. Imprimir"<<endl<<
        "3. Buscar"<<endl<<
        "4. Modificar"<<endl<<
        "5. Eliminar"<<endl<<
        "6. Salir"<<endl<<
        "Opcion: ";
        cin>>opcion;
        system("CLS");
        switch(opcion){
            case 1: 
                cout<<"AGREGAR PRODUCTO"<<endl<<endl;
                cout<<"Nombre: ";
                fflush(stdin);
                getline(cin, nombre);
                cout<<"Costo: ";
                cin>>costo;
                cout<<"Precio: ";
                cin>>precio;
                cout<<"Codigo: ";
                fflush(stdin);
                getline(cin, codigo);
                cout<<"Existencias: ";
                cin>>existencias;
                productos.agregar(nombre, costo, precio, codigo, existencias);
            break;
            case 2: 
                cout<<"IMPRIMIR PRODUCTOS"<<endl<<endl;
                cout<<fixed<<setprecision(2)<<productos;
                system("PAUSE");
            break;
            case 3: 
                cout<<"BUSCAR PRODUCTO"<<endl<<endl;
                cout<<"Buscar: ";
                fflush(stdin);
                getline(cin, busqueda);
                productos.buscar(busqueda);
                system("PAUSE");
            break;
            case 4: 
                cout<<"MODIFICAR PRODUCTO"<<endl<<endl;
                cout<<fixed<<setprecision(2)<<productos<<endl<<endl;
                productos.modificar();
            break;
            case 5: 
                cout<<"ELIMINAR PRODUCTO"<<endl<<endl;
                cout<<fixed<<setprecision(2)<<productos<<endl<<endl;
                productos.eliminar();
            break;
        }
    }while(opcion!=6);
    productos.escribir(nombreArchivo);
}

void Lista::agregar(string _nombre, float _costo, float _precio, string _codigo, int _existencias){
    Producto *producto = new Producto(_nombre, _costo, _precio, _codigo, _existencias);
    Producto *aux1 = head, *aux2;
    while(aux1 != nullptr){
        aux2 = aux1;
        aux1 = aux1 -> next;
    }
    if(head == aux1)
        head = producto;
    else
        aux2 -> next = producto;
        producto -> next = aux1;
}

void Lista::buscar(string busqueda){
    bool primera = true;
    if(head == nullptr)
        cout<<"Sin Resultados";
    else{
        int posicion = 0;
        Producto *producto = head;
        while(producto != nullptr){
            if(busqueda == producto->getNombre()){
                if(primera)
                    cout<<"Resultados"<<endl<<endl;
                primera = false;
                cout<<"Nombre: "<<"|"<<producto->getNombre()<<"|"<<endl<<
                "Costo: "<<producto->getCosto()<<endl<<
                "Precio: "<<producto->getPrecio()<<endl<<
                "Codigo: "<<producto->getCodigo()<<endl<<
                "Existencias: "<<producto->getExixtencias()<<endl<<endl;
            }
            if(busqueda == producto->getCodigo()){
                if(primera)
                    cout<<"Resultados"<<endl<<endl;
                primera = false;
                cout<<"Nombre: "<<producto->getNombre()<<endl<<
                "Costo: "<<producto->getCosto()<<endl<<
                "Precio: "<<producto->getPrecio()<<endl<<
                "Codigo: "<<"|"<<producto->getCodigo()<<"|"<<endl<<
                "Existencias: "<<producto->getExixtencias()<<endl<<endl;
                return;
            }
            posicion ++;
            producto = producto->next;
        }
        if(primera)
            cout<<endl<<endl<<"Sin Resultados"<<endl;
    }
}

void Lista::modificar(){
    if(head == nullptr){
        cout<<"No hay Productos"<<endl;
        system("PAUSE");
        return;
    }
    int posicion, opcion, existencias;
    string nombre, codigo;
    float costo, precio;
    cout<<"Cual desea modificar: ";
    cin>>posicion;
    posicion--;
    Producto *producto = head;
    if(posicion>0){
        for(int i=0; i<posicion-1; i++)
            if(producto!=nullptr)
                producto=producto->next;
        if(producto!=nullptr)
            producto = producto->next;
        else{
            cout<<endl<<"El elemento a borrar no existe"<<endl;
            return;
        }
    }
    system("CLS");
    cout<<"MODIFICAR PRODUCTO"<<endl<<endl<<
    "1. Nombre: "<<producto->getNombre()<<endl<<
    "2. Costo: "<<producto->getCosto()<<endl<<
    "3. Precio: "<<producto->getPrecio()<<endl<<
    "4. Codigo: "<<producto->getCodigo()<<endl<<
    "5. Existencias: "<<producto->getExixtencias()<<endl<<
    "6. Cancelar: "<<endl<<endl<<
    "Opcion: ";
    cin>>opcion;
    system("CLS");
    switch(opcion){
        case 1:
            cout<<"Modificar Nombre"<<endl<<endl<<
            "Digite el nuevo Nombre: ";
            fflush(stdin);
            getline(cin, nombre);
            producto->setNombre(nombre);
        break;
        case 2:
            cout<<"Modificar Costo"<<endl<<endl<<
            "Digite el nuevo Costo: ";
            fflush(stdin);
            cin>>costo;
            producto->setCosto(costo);
        break;
        case 3:
            cout<<"Modificar Precio"<<endl<<endl<<
            "Digite el nuevo Precio: ";
            fflush(stdin);
            cin>>precio;
            producto->setPrecio(precio);
        break;
        case 4:
            cout<<"Modificar Codigo"<<endl<<endl<<
            "Digite el nuevo Codigo: ";
            fflush(stdin);
            getline(cin, codigo); 
            producto->setCodigo(codigo);
        break;
        case 5:
            cout<<"Modificar Existencias"<<endl<<endl<<
            "Digite las nuevas Existencias: ";
            fflush(stdin);
            cin>>existencias;
            producto->setExistencias(existencias);
        break;
        case 6:
            return;
        break;
    }
    cout<<endl<<"Elemento Modificado"<<endl;
}

void Lista::eliminar(){
    if(head == nullptr){
        cout<<"No hay Productos"<<endl;
        system("PAUSE");
        return;
    }
    int posicion;
    cout<<"Cual desea borrar: ";
    cin>>posicion;
    posicion--;
    if(posicion==0){
        Producto *producto = head;
        head = head -> next;
        delete producto;
        cout<<endl<<"Elemento Borrado"<<endl;
    }
    else{
        Producto *producto = head;
        for(int i=0; i<posicion-1; i++)
            if(producto!=nullptr)
                producto=producto->next;
        if(producto!=nullptr)
        {
            Producto *borrar = producto->next, *despues = borrar->next;
            producto->next = despues;
            delete borrar;
            cout<<endl<<"Elemento Borrado"<<endl;
        }
        else
            cout<<endl<<"El elemento a borrar no existe"<<endl;
    }
}

void Lista::escribir(string nombreArchivo){
    ofstream archivo;
    archivo.open(nombreArchivo, ios::out);
    if(archivo.fail()){
        cout<<"No se pudo escribir en el Archivo";
        exit(1);
    }
    if(head == nullptr)
        return;
    Producto *producto;
    producto = head;
    int posicion = 1;
    while(producto != nullptr){
        archivo<<fixed<<setprecision(2);
        archivo<<"["<<producto->getNombre().length()<<"]"<<producto->getNombre()<<","<<
        "["<<(to_string(producto->getCosto()).length())-4<<"]"<<producto->getCosto()<<","<<
        "["<<(to_string(producto->getPrecio()).length())-4<<"]"<<producto->getPrecio()<<","<<
        "["<<producto->getCodigo().length()<<"]"<<producto->getCodigo()<<","<<
        "["<<to_string(producto->getExixtencias()).length()<<"]"<<producto->getExixtencias()<<";";
        posicion++;
        producto = producto -> next;
    }
    archivo.close();
}
