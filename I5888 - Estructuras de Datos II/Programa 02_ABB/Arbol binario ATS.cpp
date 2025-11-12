#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void write()
{
    ofstream file;
    file.open("file01.txt",ios::out);
    if(file.fail())
    {
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    file<<"XD";
    file.close();
}

class Node
{
    private:
        int Val;
        Node *Right;
        Node *Left;
    public:
        Node();
        Node(int, Node &, Node &);
        int getVal(){return Val;}
        void setVal(int val){Val=val;}
        Node getRight(){return *Right;}
        void setRight(Node *right){*Right=*right;}
        Node getLeft(){return *Left;}
        void setLeft(Node *left){*Left=*left;}
        Node *newNode(int v);
        void insertNode(Node *&tree, int v);
        void showTree(Node *tree, int cont);
        void preOrder(Node *tree);
        void inOrder(Node *tree);
        void postOrder(Node *tree);
};

int interface()
{
    int opc;
    cout<<"ARBOL BINARIO DE BUSQUEDA"<<endl<<endl;
    cout<<"1. Insertar valor"<<endl
    <<"2. Mostrar Arbol"<<endl
    <<"3. Pre Orden"<<endl
    <<"4. In Orden"<<endl
    <<"5. Post Orden"<<endl
    <<"6. Salir"<<endl<<endl<<"Seleccion: ";
    cin>>opc;
    return opc;
}

Node* tree = NULL;

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
                *tree->insertNode(num);
            break;
            case 2:
                system("CLS");
                *tree->showTree(cont);
                cout<<endl;
                system("PAUSE");
            break;
            case 3:
                system("CLS");
                *tree->preOrder();
                cout<<endl;
                system("PAUSE");
            break;
            case 4:
                system("CLS");
                *tree->inOrder();
                cout<<endl;
                system("PAUSE");
            break;
            case 5:
                system("CLS");
                *tree->postOrder();
                cout<<endl;
                system("PAUSE");
            break;
            case 6:
            break;
            default:
                cout<<endl<<"Seleccion incorrecta, intentelo de nuevo"<<endl<<endl;
                system("PAUSE");
        }
        system("CLS");
    }while(opc!=6);
}

Node::Node *newNode(int v)
{
    Node *new_node = new Node();

    new_node->Val=v;
    new_node->Right=NULL;
    new_node->Left=NULL;

    return new_node;
}

void Node::insertNode(Node *&tree, int v)
{
    if(tree==NULL)
    {
        Node *new_node = newNode(v);
        tree=new_node;
    }
    else{
        int rootval = tree->Val;
        if(v<rootval)
        {
            insertNode(tree->Left,v);
        }
        if(v>rootval)
        {
            insertNode(tree->Right,v);
        }
    }
}

void Node::showTree(Node *tree, int cont)
{
    if(tree==NULL)
    {
        return;
    }
    else{
        showTree(tree->right, cont+1);
        for(int i=0;i<cont;i++)
            cout<<"   ";
        cout<<tree->Val<<endl;
        showTree(tree->Left, cont+1);
    }
}

void Node::preOrder(Node *tree)
{
    if(tree==NULL)
    {
        return;
    }
    else{
        cout<<tree->Val<<" - ";
        preOrder(tree->Left);
        preOrder(tree->Right);
    }
}

void Node::inOrder(Node *tree)
{
    if(tree==NULL)
    {
        return;
    }
    else{
        inOrder(tree->Left);
        cout<<tree->Val<<" - ";
        inOrder(tree->Right);
    }
}

void Node::postOrder(Node *tree)
{
    if(tree==NULL)
    {
        return;
    }
    else{
        postOrder(tree->Left);
        postOrder(tree->Right);
        cout<<tree->Val<<" - ";
    }
}