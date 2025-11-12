 #include <iostream>
using namespace std;

class Vertex
{
    public:
        int val;
        Vertex *next;
        Vertex(int v){val=v;next=NULL;}
};

class SLList
{
    private:
        Vertex *head, *tail;
    public:
        SLList(){head=tail=NULL;}
        void insertHead(int v);
        void insertTail(int v);
        void insertAt(int i, int v);
        void search(int v);
        void deleteHead();
        void deleteTail();
        void deleteAt(int i);
        friend ostream& operator<<(ostream &out, const SLList &list)
        {
            if(list.head==NULL)
            {
                out<<"Lista vacia";
            }
            Vertex *temp;
            temp=list.head;
            while(temp!=NULL)
            {
                out<<temp->val<<"->";
                temp=temp->next;
            }
            out<<endl;
            return out;
        }
};

int main()
{
    SLList list;
    cout<<list;
    list.insertTail(6);
    cout<<list;
    list.insertHead(5);
    cout<<list;
    list.insertHead(7);
    cout<<list;
    list.deleteTail();
    cout<<list;
    list.deleteAt(1);
    cout<<list;
    list.insertHead(15);
    cout<<list;
    list.insertAt(4,10);
    cout<<list;
    list.insertTail(20);
    list.search(15);
    list.search(10);
    list.insertTail(8);
    cout<<list;
    list.deleteTail();
    cout<<list;
    list.deleteHead();
    cout<<list;
    list.insertHead(7);
    cout<<list;
    cout<<endl;
    system("PAUSE");
    return 0;
}

void SLList::insertHead(int v)
{
    Vertex *vtx = new Vertex(v);
    vtx->next=head;
    head=vtx; 
    if(tail==NULL)
    {
        tail=head;
    }
}

void SLList::insertTail(int v)
{
    if(tail==NULL)
    {
        insertHead(v);
        return;
    }
    Vertex *vtx = new Vertex(v);
    tail->next=vtx;
    tail=vtx;
}

void SLList::insertAt(int i, int v)
{
    int k;
    Vertex *pre=head;
    for(k=0;k<i-1;k++)
        if(pre->next!=NULL)
            pre=pre->next;
    if(pre->next!=NULL)
    {
        Vertex *aft=pre->next;
        Vertex *vtx = new Vertex(v);
        vtx->next=aft;
        pre->next=vtx;
    }
    else
        insertTail(v);
}

void SLList::search(int v)
{
    if(head==NULL)
    {
        cout<<"Nada que buscar"<<endl;
        return;
    }
    int index=0;
    Vertex *temp=head;
    while((temp!=NULL)&&(temp->val!=v))
    {
        index++;
        temp = temp->next;
    }
    if(temp==NULL)
    {
        cout<<"NO encontrado"<<endl;
        return;
    }
    cout<<index<<endl;
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

void SLList::deleteTail()
{
    if(head==NULL)
    {
        cout<<"Nada que borrar"<<endl;
        return;
    }
    Vertex *pre = head;
    Vertex *temp = head->next;
    while(temp->next!=NULL)
    {
        temp = temp->next;
        pre = pre->next;
    }
    if(pre!=NULL)
    {
        Vertex *del = pre->next, *aft = del->next;
        pre->next = aft;
        delete del;
    }
}

void SLList::deleteAt(int i)
{
    int k;
    if(head==NULL)
    {
        cout<<"Nada que borrar"<<endl;
        return;
    }
    Vertex *pre = head;
    for(k=0;k<i-1;k++)
        if(pre!=NULL)
            pre=pre->next;
    if(pre!=NULL)
    {
        Vertex *del = pre->next, *aft = del->next;
        pre->next = aft;
        delete del;
    }
    else
        cout<<"No existe valor en ese espacio"<<endl;
}