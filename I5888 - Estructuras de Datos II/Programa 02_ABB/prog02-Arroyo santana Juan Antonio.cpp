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
        Node *Parent;
    public:
        Node();
        Node(int, Node *);
        int getVal(){return Val;}
        void setVal(int val){Val=val;}
        Node getRight(){return *Right;}
        void setRight(Node *right){*Right=*right;}
        Node getLeft(){return *Left;}
        void setLeft(Node *left){*Left=*left;}
        Node getParent(){return *Parent;}
        void setParent(Node *parent){*Parent=*parent;}
        Node *insertNode(Node *, int, Node *);
        void deleteN(Node *, int);
        void deleteNode(Node *);
        Node *min(Node *);
        void replace(Node *, Node *);
        void destroyNode(Node *);
        void inOrder(Node *);
        void preOrder(Node *);
        void postOrder(Node *);
        void save(Node *);
};

void load();
int interface();

bool newFile;
Node tree, *root=nullptr;

int main(void)
{
    int opc, num;
    do{
        opc=interface();
        switch(opc)
        {
            case 1:
                system("CLS");
                cout<<"Inserte un numero a insertar: ";
                cin>>num;
                root = tree.insertNode(root, num, nullptr);
            break;
            case 2:
                system("CLS");
                cout<<"Inserte el numero a borrar: ";
                cin>>num;
                tree.deleteN(root, num);
                cout<<endl<<endl<<endl;
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
                tree.save(root); 
            break;
            case 7:
                load();
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
    Parent=nullptr;
}

Node::Node(int val, Node *parent)
{
    Val=val;
    Left=nullptr;
    Right=nullptr;
    Parent=parent;
}

Node *Node::insertNode(Node *root, int val, Node *parent)
{
    if(!root)
        return new Node(val, parent);
    if(val>root->Val)
        root->Right = insertNode(root->Right, val, root);
    if(val<root->Val)
        root->Left = insertNode(root->Left, val, root);
    return root;
}

void Node::deleteN(Node *root, int val)
{
    if(!root)
    {
        cout<<endl<<"Nodo no encontrado";
        return;
    }
    else if(val<root->Val)
        deleteN(root->Left, val);
    else if(val>root->Val)
        deleteN(root->Right, val);
    else if(root->Val == val)    
    {  
        deleteNode(root);
        cout<<endl<<"Nodo borrado correctamente";
    }
}

void Node::deleteNode(Node *delNode)
{
    if(delNode->Left&&delNode->Right)
    {
        Node *minor = min(delNode->Right);
        delNode->Val = minor->Val;
        deleteNode(minor);
    }
    else if(delNode->Left)
    {
        replace(delNode, delNode->Left);
        destroyNode(delNode);
    }
    else if(delNode->Right)
    {
        replace(delNode, delNode->Right);
        destroyNode(delNode);
    }
    else
    {
        replace(delNode, nullptr);
        destroyNode(delNode);
    }
}

Node* Node::min(Node *root)
{
    if(!root)
        return nullptr;
    if(root->Left)
        return min(root->Left);
    else
        return root;
}

void Node::replace(Node *root, Node *newNode)
{
    if(root->Parent)
    {
        if(root->Parent->Left)
            if(root->Val == root->Parent->Left->Val)
                root->Parent->Left = newNode;
        if(root->Parent->Right)
            if(root->Val==root->Parent->Right->Val)
                root->Parent->Right = newNode;
    }
    if(newNode)
        newNode->Parent = root->Parent;
}

void Node::destroyNode(Node *delNode)
{
    delNode->Left=nullptr;
    delNode->Right=nullptr;
    delete delNode;
}

void Node::inOrder(Node *root)
{
    if(!root)
        return;
    inOrder(root->Left);
    cout<<root->Val<<endl;
    inOrder(root->Right);
}

void Node::preOrder(Node *root)
{
    if(!root)
        return;
    else{
        cout<<root->Val<<endl;
        preOrder(root->Left);
        preOrder(root->Right);
    }
}

void Node::postOrder(Node *root)
{
    if(!root)
        return;
    else{
        postOrder(root->Left);
        postOrder(root->Right);
        cout<<root->Val<<endl;
    }
}

void Node::save(Node *root)
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
            save(root->Left);
            save(root->Right); 
        }
    }
}

void load()
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
            root = tree.insertNode(root, num, nullptr);
        }
    }
    file.close();
}

int interface()
{
    int opc;
    cout<<"ARBOL BINARIO DE BUSQUEDA"<<endl<<endl;
    cout<<"1. Insertar valor"<<endl
    <<"2. Borrar Nodo"<<endl
    <<"3. Pre Orden"<<endl
    <<"4. In Orden"<<endl
    <<"5. Post Orden"<<endl
    <<"6. Guardar"<<endl
    <<"7. Cargar"<<endl
    <<"8. Salir"<<endl<<endl<<"Seleccion: ";
    cin>>opc;
    return opc;
}