#include <iostream>
using namespace std;

class Vertex
{
    public:
        int val;
        Vertex *left, *right;
        Vertex(int v){val=v;left=right=NULL;}
};

class BinaryTree
{
    private:
        Vertex *root;
    public:
        BinaryTree(){root=NULL;}
        void insert(int);
        void del();
        void print()
        {
            
        }
        void printPre();
        void printPost();
        void printInOrder();
};

int main (void)
{
    BinaryTree tree;
    int opc, num;
    do{
        cout<<"ARBOL BINARIO DE BUSQUEDA"<<endl<<endl;
        cout<<"1. Insertar valor"<<endl
        <<"2. Salir"<<endl<<endl<<"Seleccion: ";
        cin>>opc;
        switch(opc)
        {
            case 1:
            cout<<"Inserte un numero: ";
            cin>>num;
            tree.insert(num);
        }
        system("PAUSE");
        system("CLS");
    }while(opc!=2);
}


void BinaryTree::insert(int v)
{
    Vertex *vtx = new Vertex(v);
    vtx->val=v;
    vtx->right=NULL;
    vtx->left=NULL;
    if(root==NULL)
    {
        root=vtx;
        return;
    }
    else
    {
        int rootval = root->val;
        vtx=root;
        if(v<rootval)
        {
            vtx=vtx->left;
            vtx->val=v;
        }
        if(v>rootval)
        {
            vtx=vtx->right;
            vtx->val=v;
        }
    }
}