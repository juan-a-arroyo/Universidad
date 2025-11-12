#include <iostream>
using namespace std;

class Vertex
{
    public:
        int val;
        Vertex *next;
        Vertex(int v){val=v;next=NULL;}
};

class Queue
{
    private:
        Vertex *head, *tail;
    public:
        Queue(){head=tail=NULL;}
        void Peek();
        void Enqueue(int v);
        void Dequeue();
};

int main()
{
    Queue queue;
    queue.Peek();
    queue.Enqueue(20);
    queue.Enqueue(44);
    queue.Enqueue(128);
    queue.Peek();
    queue.Dequeue();
    queue.Peek();
    queue.Dequeue();
    queue.Peek();
    queue.Dequeue();
    queue.Peek();
    queue.Enqueue(256);
    queue.Enqueue(512);
    queue.Dequeue();
    queue.Peek();
    queue.Dequeue();
    queue.Dequeue();
    system("PAUSE");
    return 0;
}

void Queue::Peek()
{   
    if(head==NULL)
    {
        cout<<"Cola Vacia"<<endl;
        return;
    }
    Vertex *temp;
    temp=head;
    cout<<temp->val<<endl;
    return;
}

void Queue::Enqueue(int v)
{
    Vertex *vtx = new Vertex(v);
    if(tail==NULL)
    {
        vtx->next=head;
        head=vtx;
        return;
    }
    tail->next=vtx;
    tail=vtx;
}

void Queue::Dequeue()
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