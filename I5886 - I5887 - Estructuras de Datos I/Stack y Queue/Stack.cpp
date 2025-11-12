#include <iostream>
using namespace std;

class Vertex
{
    public:
        int val;
        Vertex *next;
        Vertex(int v){val=v;next=NULL;}
};

class Stack
{
    private:
        Vertex *head;
    public:
        Stack(){head=NULL;}
        void Peek();
        void Push(int v);
        void Pop();
};

int main()
{
    Stack stack;
    stack.Peek();
    stack.Push(20);
    stack.Push(44);
    stack.Push(25);
    stack.Peek();
    stack.Push(8);
    stack.Push(9);
    stack.Peek();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Peek();
    system("PAUSE");
    return 0;
}

void Stack::Peek()
{   
    if(head==NULL)
    {
        cout<<"Pila Vacia"<<endl;
        return;
    }
    Vertex *temp;
    temp=head;
    cout<<temp->val<<endl;
    return;
}

void Stack::Push(int v)
{
    Vertex *vtx = new Vertex(v);
    vtx->next=head;
    head=vtx;
}

void Stack::Pop()
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