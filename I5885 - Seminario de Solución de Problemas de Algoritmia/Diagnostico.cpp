#include <iostream>
using namespace std;

class Package 
{
    private:
        long ID;
        string Origin;
        string Destination;
        float Weight;
    public:
        Package(){};
        Package(long id, string origin, string destination, float weight)
        {
            ID=id;
            Origin=origin;
            Destination=destination;
            Weight=weight;
        }
        void setID(long id){ID=id;}
        void setOrigin(string origin){Origin=origin;}
        void setDestiny(string destination){Destination=destination;}
        void setWeight(float weight){Weight=weight;}
        long getID(){return ID;}
        string getOrigin(){return Origin;}
        string getDestination(){return Destination;}
        float getWeight(){return Weight;}
};

class Vertex : public Package
{
    public:
        Package pack;
        Vertex *next;
        Vertex(){};
        Vertex(long id, string origin, string destination, float weight){pack=Package(id, origin, destination, weight);next=NULL;}
};

class SLList
{
    private:
        Vertex *head, *tail;
    public:
        SLList(){head=tail=NULL;}
        void insertHead(long, string, string, float);
        void deleteHead();
        void showList(SLList);
};

int main (void)
{
    SLList paquete;
    int opc;
    long id;
    string origin, destination;
    float weight;
    do{
        system("CLS");
        cout<<"PAQUETERIA"<<endl<<endl
        <<"1. Agregar Paquete"<<endl
        <<"2. Eliminar Paquete"<<endl
        <<"3. Mostrar"<<endl
        <<"4. Salir"<<endl<<endl
        <<"Seleccion: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
            system("CLS");
            cout<<"Ingrese el ID del paquete: ";
            cin>>id;
            cout<<"Ingrese el Origen del paquete: ";
            cin>>origin;
            cout<<"Ingrese el Destino del paquete: ";
            cin>>destination;
            cout<<"Ingrese el Peso del paquete (Kg): ";
            cin>>weight;
            paquete.insertHead(id, origin, destination, weight);
        break;
        case 2:
            paquete.deleteHead();
        break;
        case 3:
            system("CLS");
            cout<<"MOSTRAR PAQUETES"<<endl<<endl;
            paquete.showList(paquete);
            system("PAUSE");
        break;
        }
    }while(opc!=4);
}

void SLList::insertHead(long id, string origin, string destination, float weight)
{
    Vertex *vtx = new Vertex(id, origin, destination, weight);
    vtx->next=head;
    head=vtx; 
    if(tail==NULL)
    {
        tail=head;
    }
}
void SLList::deleteHead()
{
    if(head==NULL)
    {
        cout<<"Nada que borrar"<<endl;
        return;
    }
    Vertex *temp=head;
    head = head->next;
    delete temp;
}

void SLList::showList(SLList list)
{
    if(list.head==NULL)
    {
        cout<<"Lista vacia";
    }
    Vertex *temp;
    temp=list.head;
    while(temp!=NULL)
    {
        cout<<"ID: "<<temp->pack.getID()<<" // Origen: "<<temp->pack.getOrigin()<<" // Destino: "<<temp->pack.getDestination()
        <<" // Peso: "<<temp->pack.getWeight()<<"Kg"<<endl<<endl;
        temp=temp->next;
    }
    cout<<endl;
}