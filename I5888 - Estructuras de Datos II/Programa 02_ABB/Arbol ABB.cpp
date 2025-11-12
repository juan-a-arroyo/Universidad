#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Node
{
    private:
        int Val;
        Node *Left;
        Node *Right;
    public:
        Node();
        Node(int);
        Node* insertNode(Node*, int);
        void showTree(Node*, int);
        void inOrder(Node*);
        void preOrder(Node*);
        void postOrder(Node*);
        void write(Node*);
};

void read();
int interface();

bool newFile;
Node tree, *root=nullptr;

int main(void)
{
    int opc, num, cont=0;
    do{
        opc=interface();
        switch(opc)
        {
            case 1:
                system("CLS");
                cout<<"Inserte un numero: ";
                cin>>num;
                root = tree.insertNode(root, num);
            break;
            case 2:
                system("CLS");
                cout<<"Mostrar Arbol"<<endl<<endl;
                tree.showTree(root, cont);
                cout<<endl;
                system("PAUSE");
            break;
            case 3:
                system("CLS");
                cout<<"Pre orden"<<endl<<endl;
                tree.preOrder(root);
                cout<<endl;
                system("PAUSE");
            break;
            case 4:
                system("CLS");
                cout<<"In orden"<<endl<<endl;
                tree.inOrder(root);
                cout<<endl;
                system("PAUSE");
            break;
            case 5:
                system("CLS");
                cout<<"Post orden"<<endl<<endl;
                tree.postOrder(root);
                cout<<endl;
                system("PAUSE");
            break;
            case 6:
                newFile=true;
                tree.write(root); 
            break;
            case 7:
                read();
            break;
            case 8:
            break;
            default:
                cout<<endl<<"Seleccion incorrecta, intentelo de nuevo"<<endl<<endl;
                system("PAUSE");
        }
        system("CLS");
    }while(opc!=8);
}

Node::Node()
{
    Val=0;
    Left=nullptr;
    Right=nullptr;
}

Node::Node(int val)
{
    Val=val;
    Left=Right=nullptr;
}

Node* Node::insertNode(Node* root, int val)
{
    if(!root)
        return new Node(val);
    if(val>root->Val)
        root->Right = insertNode(root->Right, val);
    if(val<root->Val)
        root->Left = insertNode(root->Left, val);
    return root;
}

void Node::showTree(Node* root, int cont)
{
    if(!root)
        return;
    else{
        showTree(root->Right, cont+1);
        for(int i=0;i<cont;i++)
            cout<<"   ";
        cout<<root->Val<<endl;
        showTree(root->Left, cont+1);
    }
}

void Node::inOrder(Node* root)
{
    if(!root)
        return;
    inOrder(root->Left);
    cout<<root->Val<<endl;
    inOrder(root->Right);
}

void Node::preOrder(Node* root)
{
    if(!root)
        return;
    else{
        cout<<root->Val<<endl;
        preOrder(root->Left);
        preOrder(root->Right);
    }
}

void Node::postOrder(Node* root)
{
    if(!root)
        return;
    else{
        postOrder(root->Left);
        postOrder(root->Right);
        cout<<root->Val<<endl;
    }
}

void Node::write(Node* root)
{
    ofstream file;
    if(newFile==true)
        file.open("file01.txt",ios::out);
    else
        file.open("file01.txt",ios::app);
    newFile=false;
    if(file.fail())
    {
        cout<<"Error al abrir el archivo";
        return;
    }
    else  
    {
        if(root)
        {
            file<<root->Val<<"|";
            file.close();
            write(root->Left);
            write(root->Right); 
        }
    }
}

void read()
{
    int num;
    string strVal;
    ifstream file;
    file.open("file01.txt",ios::in);
    if(file.fail())
    {
        cout<<"Error al abrir el archivo";
        return;
    }
    while(getline(file,strVal))
    {
        stringstream stream(strVal);
        string val;
        while(getline(stream, val, '|'))
        {
            num = stoi(val, nullptr, 10);
            root = tree.insertNode(root, num);
        }
    }
    file.close();
}

int interface()
{
    int opc;
    cout<<"ARBOL BINARIO DE BUSQUEDA"<<endl<<endl;
    cout<<"1. Insertar valor"<<endl
    <<"2. Mostrar Arbol"<<endl
    <<"3. Pre Orden"<<endl
    <<"4. In Orden"<<endl
    <<"5. Post Orden"<<endl
    <<"6. Guardar"<<endl
    <<"7. Cargar"<<endl
    <<"8. Salir"<<endl<<endl<<"Seleccion: ";
    cin>>opc;
    return opc;
}